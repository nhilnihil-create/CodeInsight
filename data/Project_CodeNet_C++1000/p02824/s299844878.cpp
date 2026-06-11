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
    int N,V,P;
    ll M;
    cin>>N>>M>>V>>P;
    vector<ll> A(N);
    rep(i,N){
        cin>>A.at(i);
    }
    sort(A.rbegin(),A.rend());
    vector<ll> S(N+1);
    rep(i,N){
        S.at(i+1)=S.at(i)+A.at(i);
    }

    vector<bool> judge(N,false);
    rep(i,P){judge.at(i)=true;}
    
    for(int i=P;i<N;i++){
        if(A.at(i)==A.at(i-1)){
            judge.at(i)=judge.at(i-1);
            continue;
        }
        if(V-(N-i)-(P-1)<=0){
            if(A.at(i)+M>=A.at(P-1)){
                judge.at(i)=true;
            }
        }
        else{
            if(A.at(i)+M<A.at(P-1))continue;
            if((A.at(i)+M)*(i-P+1)-(S.at(i)-S.at(P-1))>=M*(V-(N-i)-(P-1))){
                //cout<<(A.at(i)+M)<<" "<<(i-P+1)<<" "<<(S.at(i)-S.at(P-1))<<" "<<(V-(N-i)-(P-1))<<endl;
                judge.at(i)=true;
            }
        }
    }
    int ans=0;
    rep(i,N){
        if(judge.at(i))ans++;
    }
    cout<<ans<<endl;
}