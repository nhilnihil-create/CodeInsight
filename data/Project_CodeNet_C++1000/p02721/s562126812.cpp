#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N,K,C;cin>>N>>K>>C;
    string S,Q;cin>>S;
    Q=S;
    reverse(Q.begin(),Q.end());
    vector<int>lvec;
    int j=0;
    for(int i=0;i<N&&j<K;i++){
        if(S[i]=='o'){
          	lvec.push_back(i+1);
            j++;
            i+=C;
        }
    }
    lvec.resize(j);
    vector<int>rvec;
    int k=0;
    for(int i=0;i<N&&k<K;i++){
        if(Q[i]=='o'){
            rvec.push_back(N-i);
            k++;
            i+=C;
        }
    }
    rvec.resize(k);
    reverse(rvec.begin(),rvec.end());
    REP(i,min(j,k)){
        if(lvec[i]==rvec[i]) cout<<lvec[i]<<endl;
    }
}