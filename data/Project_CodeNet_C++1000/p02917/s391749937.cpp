#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    vector<int> a(n);
    a[0] = b[0];
    for(int i = 1; i < n - 1; ++i)
        a[i] = min(b[i], b[i - 1]);
    
    ll res = 0;
    a[n - 1] = b[n - 2];
    for(int i = 0; i < n; ++i)
        res += a[i];

    cout << res << "\n";
    return 0;
}