#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 9; ++j)
            if(i * j == n)
            {
                cout << "Yes" << "\n";
                return 0;
            }

    cout << "No" << "\n";
    return 0;
}
