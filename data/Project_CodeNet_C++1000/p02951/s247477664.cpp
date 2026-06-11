#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;



int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(b+c-a,0)<<endl;
}
