#include<bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const long long MOD=(long long)(1e9+7);
const int NAX=1005;
Int N,M,K;
Int W,H;
Int X,Y,Z;
vector<Int> A;

Int perform(Int x){
    return (x*(x+1))/2LL;
}
int main()
{
    cin>>N;
    vector<pair<Int,Int>> pairs;
    for(int i=0;i<N;++i){
        Int u,v;
        cin>>u>>v;
        pairs.pb({u,v});
    }
    
    bool fine=false;
    int K=3;
    Int times=0;
    for(int i=0;i<K;++i){
        times+=(pairs[i].first==pairs[i].second);
    }
    if(times==3){
        fine=true;
    }
    
    for(int i=K;i<N;++i){
        times+=pairs[i].first==pairs[i].second;
        times-=pairs[i-K].first==pairs[i-K].second;
        if(times==3) fine=true;
    }
    cout<<(fine ? "Yes\n":"No\n");
}