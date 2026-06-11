#include <iostream>

using namespace std;

int main()
{
    int n,m,t;
    cin >> n >> m;
    int matrix [n][m];
    int Vector [m], result [n] = {0};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for(int j = 0; j < m; j++)
            cin >> Vector[j];

    for(int f = 0; f < n; f++)
        for(int g = 0; g < m; g++)
        {
            t = (matrix[f][g] * Vector[g]);
            result[f] += t;
        }
    for(int i = 0; i < n; i++)
        cout << result[i] << endl;

    return 0;
}

