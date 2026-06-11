#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    ll n; cin >> n;
    ll ans=0;
    for(ll i=2; i*i<=n; i++) {
        if(n%i != 0) continue;
        ll ex=0;
        while(n%i == 0) {
            ex++;
            n/=i;
        }
        ll j=1;
        while(ex>0) {
            if(ex-j >= 0) {
                ans++;
                ex -= j;
                j++;
            }
            else if(ex-j < 0) break;
        }
    }
    if(n != 1) ans++;
    cout << ans << endl;
    return 0;
}