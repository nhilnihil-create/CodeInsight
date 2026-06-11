#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    double v[n];
    rep(i, n) cin >> v[i];
    sort(v, v + n);
    rep(i, n - 1)
    {
        v[i + 1] = (v[i] + v[i + 1]) / 2;
    }
    cout<<v[n-1]<<endl;
    return 0;
}