#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll ans = 0;
    for(int A=1;A<=n-1;A++){
        ans += (n-1)/A;
    }
    cout << ans << endl;
}