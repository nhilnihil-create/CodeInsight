#include <bits/stdc++.h>
using namespace std;

int main()
{

    int cartela[3][3];
    int numbers = 0;
    int count;
    int number;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cartela[i][j];
        }
    }

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> number;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                 if (number == cartela[i][j])
                    cartela[i][j] = 0;
            }
        }
    }

    if (cartela[0][0] == 0 && cartela[0][1] == 0 && cartela[0][2] == 0)
        cout << "Yes";
    else if (cartela[1][0] == 0 && cartela[1][1] == 0 && cartela[1][2] == 0)
        cout << "Yes";

    else if (cartela[2][0] == 0 && cartela[2][1] == 0 && cartela[2][2] == 0)
        cout << "Yes";

    else if (cartela[0][0] == 0 && cartela[1][0] == 0 && cartela[2][0] == 0)
        cout << "Yes";

    else if (cartela[0][1] = 0 && cartela[1][1] == 0 && cartela[2][1] == 0)
        cout << "Yes";

    else if (cartela[0][2] == 0 && cartela[1][2] == 0 && cartela[2][2] == 0)
        cout << "Yes";

    else if (cartela[0][0] == 0 && cartela[1][1] == 0 && cartela[2][2] == 0)
        cout << "Yes";

    else if (cartela[0][2] == 0 && cartela[1][1] == 0 && cartela[2][0] == 0)
        cout << "Yes";

    else
        cout << "No";
}