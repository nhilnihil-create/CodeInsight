#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n;
    string c;
    cin>>n>>c;
    ll cnt=0;
    rep(i,n){
        if(c[i]=='R') cnt++;
    }
    ll ans=0;
    rep(i,cnt){
        if(c[i]=='W') ans++;
    }
    cout<<ans<<endl;
    return 0;
}