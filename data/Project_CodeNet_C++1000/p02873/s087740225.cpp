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
    string S;
    cin>>S;
    int N=sz(S)+1;
    vector<int> A(N,-1);
    if(S.at(0)=='<')A.at(0)=0;
    if(S.at(N-2)=='>')A.at(N-1)=0;
    rep(i,N-2){
        if(S.at(i)=='>' && S.at(i+1)=='<'){
            A.at(i+1)=0;
        }
    }
    rep(i,N){
        if(A.at(i)!=0)continue;
        int pl=i-1,pr=i;
        while(pl>=0 && S.at(pl)=='>'){
            chmax(A.at(pl),A.at(pl+1)+1);
            pl--;
        }
        while(pr<N-1 && S.at(pr)=='<'){
            chmax(A.at(pr+1),A.at(pr)+1);
            pr++;
        }
    }
    ll ans=0;
    rep(i,N)ans+=A.at(i);
    cout<<ans<<endl;
}