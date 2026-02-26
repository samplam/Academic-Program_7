#include <iostream>
#include <string>
#include <array>

using namespace std;

// Function for displaying a matrix.
void affichage_matrice(array<array<int, 10>, 10> matrice, int nb_colonnes, int nb_lignes, string identifiant)
{
    cout << "Voici la matrice " << identifiant << " :" << endl;
    for (int i=0; i < nb_colonnes; i++)
    {
        for (int j=0; j < nb_lignes; j++)
        {
            // Spacing adjustment.
            if (((matrice[i][j]) / 10) >= 10)
            {
                cout << "  " << matrice[i][j];
            }
            else if (((matrice[i][j]) / 10) >= 1)
            {
                cout << "   " << matrice[i][j];
            }
            else
            {
                cout << "    " << matrice[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

    return;
}

// Function for matrix addition.
array<array<int, 10>, 10> somme_matrice(array<array<int, 10>, 10> matrice_1,array<array<int, 10>, 10> matrice_2, int nb_colonnes, int nb_lignes)
{
    array<array<int, 10>, 10> somme = {};
    for (int i=0; i < nb_colonnes; i++)
    {
        for (int j=0; j < nb_lignes; j++)
        {
            somme[i][j] = matrice_1[i][j] + matrice_2[i][j];
        }
    }

    return somme;
}

int main()
{
    // Declaration of constants and variables.
    const int nb_colonnes = 10;
    const int nb_lignes = 10;
    array<array<int, nb_colonnes>, nb_lignes> matrice_1 = {};
    array<array<int, nb_colonnes>, nb_lignes> matrice_2 = {};
    array<array<int, nb_colonnes>, nb_lignes> matrice_somme = {};


    // Generation of matrix 1 with more or less random numbers smaller than 100.
    for (int i=0; i < nb_colonnes; i++)
    {
        for (int j=0; j < nb_lignes; j++)
        {
            matrice_1[i][j] = (rand() % 100);
        }
    }

    // Generation of matrix 2 with more or less random numbers smaller than 100.
    for (int i=0; i < nb_colonnes; i++)
    {
        for (int j=0; j < nb_lignes; j++)
        {
            matrice_2[i][j] = (rand() % 100);
        }
    }

    affichage_matrice(matrice_1, nb_colonnes, nb_lignes, "1");

    affichage_matrice(matrice_2, nb_colonnes, nb_lignes, "2");

    matrice_somme = somme_matrice(matrice_1, matrice_2, nb_colonnes, nb_lignes);

    affichage_matrice(matrice_somme, nb_colonnes, nb_lignes, "somme");

    return 0;
}