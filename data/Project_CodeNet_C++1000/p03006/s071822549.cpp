#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

vector<ll> to[11];

int main(){
    ll N;cin>>N;
    double x[60],y[60];
    rep(i,0,N)cin>>x[i]>>y[i];
    map<pair<ll,ll>,ll> m;
    ll cn,MAX=0;
    rep(i,0,N){
        rep(j,0,N){
            cn=1;
            if(i==j)continue;
            rep(k,0,N){
                rep(l,0,N){
                    if(k==l||(i==k&&j==l))continue;
                    if((y[j]-y[i])==(y[l]-y[k])&&(x[j]-x[i])==(x[l]-x[k]))cn++;
                    MAX=max(MAX,cn);
                }
            }
        }
    }
    
    cout<<N-MAX<<endl;

}





