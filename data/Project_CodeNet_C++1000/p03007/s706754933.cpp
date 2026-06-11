#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N){cin>>A.at(i);}
    sort(A.begin(),A.end());
    vector<int> plus(0),minus(0);
    rep(i,N){
        if(i==0){
            minus.pb(A.at(i));
        }
        else if(i==N-1){
            plus.pb(A.at(i));
        }
        else{
            if(A.at(i)>0)plus.pb(A.at(i));
            else minus.pb(A.at(i));
        }
    }
    ll ans=0;
    rep(i,sz(plus)){
        ans+=plus.at(i);
    }
    rep(i,sz(minus)){
        ans-=minus.at(i);
    }
    cout<<ans<<endl;
    int pp=1;
    while(pp<sz(plus)){
        cout<<minus.at(0)<<" "<<plus.at(pp)<<endl;
        minus.at(0)-=plus.at(pp);
        pp++;
    }
    rep(i,sz(minus)){
        cout<<plus.at(0)<<" "<<minus.at(i)<<endl;
        plus.at(0)-=minus.at(i);
    }
}