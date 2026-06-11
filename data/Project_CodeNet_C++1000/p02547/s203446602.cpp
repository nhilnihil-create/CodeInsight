#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> D(n);
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        if (a == b) D[i] = 1;
    }
    bool sol = false;
    for (int i = 2; i < n; i++)
    {
        if (D[i-2] == 1 && D[i-1] == 1 && D[i] == 1)
        {
            sol = true; break;
        }
    }
    if (sol) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
