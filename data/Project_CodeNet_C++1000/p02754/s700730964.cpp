
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    ll N,a,b;cin>>N>>a>>b;
    ll l=a+b;
    ll tmp=0;
    ll ans=0;
    ans+=a*(N/l);
    tmp=N%l;
    if(tmp>=a){
        ans+=a;
    }else{
        ans+=tmp;
    }
    cout<<ans<<endl;
}