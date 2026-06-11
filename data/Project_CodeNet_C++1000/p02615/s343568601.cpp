#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());
    int r = n%2, t = n/2;
    ll res = a[0];
    for (int i=1; i<t; i++) res += (2ll * a[i]);
    if (r == 1) res += a[t];
    cout << res << '\n';
    return 0;
}