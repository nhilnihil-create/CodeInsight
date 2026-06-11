#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    ll t1 = h1*60 + m1;
    ll t2 = h2*60 + m2;
    cout << t2 - t1 - k << endl;

    return 0;
}