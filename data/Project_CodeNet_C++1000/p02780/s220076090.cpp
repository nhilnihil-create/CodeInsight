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

D getExpectation(D x) {
   return perform(x)/x;
}

int main()
{
   cin>>N>>K;
   vector<int> A(N);
   
   for(auto &x:A) cin>>x;
   D best=0;
   D ans=0;
   
   for(int i=0;i<K;++i){
       ans+=getExpectation((D)A[i]);
   }
   best=max(best,ans);
   for(int i=K;i<N;++i){
       ans-=getExpectation((D)A[i-K]);
       ans+=getExpectation((D)A[i]);
       best=max(best,ans);
   }
   cout<<fixed<<setprecision(12)<<best<<"\n";
   
    
}