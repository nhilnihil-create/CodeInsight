#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll x,k,d;
    cin >> x >> k >> d;
    ll ans;
    if(x<0) x = -x;
    ll t = x/d;
    if(t>=k) ans = x - d * k;
    else if((k-t)%2==0) ans = x - d * t;
    else if((k-t)%2==1) ans = d - (x-d*t);
    cout << ans << endl;
}