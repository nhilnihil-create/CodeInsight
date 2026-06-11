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
    int N,K;
    cin>>N>>K;
    if(K>(N-1)*(N-2)/2){cout<<"-1"<<endl;return 0;}
    cout<<N-1+(N-1)*(N-2)/2-K<<endl;
    rep(i,N-1){
        cout<<1<<" "<<i+2<<endl;
    }
    int u=2,v=3;
    rep(i,(N-1)*(N-2)/2-K){
        cout<<u<<" "<<v<<endl;
        if(v==N){u++;v=u+1;}
        else{v++;}
    }
}