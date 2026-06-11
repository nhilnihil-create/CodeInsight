#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const long MOD=(long)(1e9+7);
vector<int> adj[MAXN];
vector<pair<int,int>> G[MAXN];

Int N,M,K;
Int B,C,H,W;
Int X,Y,Z;
vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}
using D=long double;

Int perform(Int x){
    return (x*(x+1))/2LL;
}

int main()
{
        cin>>N;
        A.resize(N);
        for(auto &x:A) cin>>x;
        
        Int ans=0;Int best=0;
        for(int i=1;i<N;++i){
            if(A[i]>A[i-1]){
                best=max(best,ans);
                ans=0;
            }
            else ++ans;
        }
        best=max(best,ans);
        cout<<best<<"\n";
        
}
