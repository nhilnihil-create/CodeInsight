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
     map<char,int> mp;
     string S;cin>>S;
     for(auto x:S) ++mp[x];
     
     bool ok=true;
     if(mp.size()!=2) ok=false;
     for(auto &itr:mp){
         if(itr.second!=2)  ok=false;
     }
     cout<<(ok ? "Yes\n":"No\n");
}
