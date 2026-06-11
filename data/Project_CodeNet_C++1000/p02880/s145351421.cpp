#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k[100];
    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i * j == n)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}