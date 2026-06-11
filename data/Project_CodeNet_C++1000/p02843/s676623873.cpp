#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll x;
    cin >> x;
    ll tmp = x%100;
    ll spare = (x - tmp)/100;
    ll cnt = 0;
    cnt += tmp/5;
    tmp %= 5;
    if(tmp != 0) ++cnt;
    if(spare >= cnt) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}