#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a, b(n);
    rep(i, n - 1)
    {
        cin >> b[i];
    }
    a.push_back(b[0]);
    rep(i, n - 2) a.push_back(min(b[i], b[i + 1]));
    a.push_back(b[n - 2]);
    cout<<accumulate(a.begin(), a.end(), 0)<<endl;
    // rep(i, n ) cout << a[i];
    return 0;
}