#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int nexon = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        nexon ^= a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (a[i] ^ nexon) << " ";
    }

    return 0;
}
