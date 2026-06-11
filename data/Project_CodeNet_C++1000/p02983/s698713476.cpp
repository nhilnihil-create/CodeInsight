#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e5+5;
const ll mod = 1e9+7;
void solve(){
    ll l,r;
    cin>>l>>r;
    if(r-l>2222){
        cout<<0<<endl;
        return ;
    }
    ll ans = 1e9;

    for(ll i=l;i<=r;i++){
        for(ll j=i+1;j<=r;j++){
            ans = min(ans,(i*j)%2019);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
