#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll n,ans=0;
    string s,t;
    cin>>n>>s;
    t=s;
    sort(t.begin(),t.end());
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]) ans++;
    }
    cout<<ans/2<<endl;
}