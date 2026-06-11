#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,K,S; cin>>N>>K>>S;
    vector<int64_t> V(N,10e8);

    if(S==10e8){
        rep(i,0,N-K) V.at(i)=1;
    }else{
        rep(i,0,K) V.at(i)=S;
    }

    for(auto v:V) cout<<v<<" ";
    cout<<endl;
}