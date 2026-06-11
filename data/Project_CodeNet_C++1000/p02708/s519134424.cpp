#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>sum(n+2,0);
    rep(i,0,n+1){
        sum.at(i+1)=sum.at(i)+i;
    }
    ll ans=0;
    rep(i,k,n+2){
        ans+=(sum.at(n+1)-sum.at(n+1-i))-sum.at(i)+1;
        //cout<<ans<<endl;
    }
    cout<<ans%1000000007<<endl;
return 0;
}