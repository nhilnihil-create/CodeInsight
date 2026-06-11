#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    ll n,sum1=0,sum2=0,ans=1e18;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum1 += a[i];
    }
    rep(i,n){
        sum2 += a[i];
        ans = min(ans, abs(sum1 - sum2*2));
    }
    cout << ans << endl;
}