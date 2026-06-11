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
    int N,L;
    cin>>N>>L;
    int ans=0;
    int mn=10000;
    rep(i,N){
        ans+=L+i;
        if(abs(L+i)<abs(mn)){mn=L+i;}
    }
    ans-=mn;
    cout<<ans<<endl;
}