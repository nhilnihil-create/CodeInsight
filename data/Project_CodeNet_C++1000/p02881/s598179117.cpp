#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin >> n;
    ll s = (int)sqrt(n);
    ll t;
    while(1){
        if(!(n%s)) { t = n/s; break;}
        s--;
    }

    ll ans = s + t - 2;

    cout << ans << endl;

    return 0;
} 