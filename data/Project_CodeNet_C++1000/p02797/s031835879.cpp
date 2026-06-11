#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int N,K,S;
    cin>>N>>K>>S;
    if(S<1e9){
        rep(i,K){cout<<S<<endl;}
        rep(i,N-K){cout<<S+1<<endl;}
    }
    else{
        rep(i,K){cout<<S<<endl;}
        rep(i,N-K){cout<<1<<endl;}
    }
}