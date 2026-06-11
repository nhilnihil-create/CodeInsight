#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll n;
ll ans=0;
int main(){
    cin>>n;
    ll tmp;
    for(ll i=1;i*i<=n;++i)if(n%i==0){
        tmp=n;
        if(i!=1&&i*i!=n){
        while(tmp%i==0) tmp/=i;
        if(tmp%i==1) ++ans;
        }
        tmp=n;
        while(tmp%(n/i)==0) tmp/=(n/i);
        if(tmp%(n/i)==1) ++ans;
        //if(n%i==0) ans+=2;
        //if(n==i*i) --ans;
    }
    --n;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0) ans+=2;
        if(n==i*i) --ans;
    }
    if(n!=1)++ans;
    cout<<ans<<endl;
    return 0;
}