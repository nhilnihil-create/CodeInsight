#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;

int main(){
    ll n;cin>>n;
    ll ans = 1;
    for (ll i= 2;i*i<=n;i++){
        if ((n-1)%i==0&&((n-1)/i>sqrt(n))) ans++;
        ll m = n;
        while (m%i==0){
            m/=i;
        }
        if (m%i==1) ans++;
    }
    if (n>2) ans++;
    cout << ans << endl;
}