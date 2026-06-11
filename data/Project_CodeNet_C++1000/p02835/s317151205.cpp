#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll ans = 0;
    for(i = 0;i < 3;++i){
        ll a;
        cin >> a;
        ans += a;
    }
    if(ans <= 21) cout << "win" << endl;
    else cout << "bust" << endl;
    return 0;
}