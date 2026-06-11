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
    int X,Y;
    cin>>X>>Y;
    int ans=0;
    ans+=max(0,400000-100000*X);
    ans+=max(0,400000-100000*Y);
    if(X==1 && Y==1){ans+=400000;}
    cout<<ans<<endl;
}