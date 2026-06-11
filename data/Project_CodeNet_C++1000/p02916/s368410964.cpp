#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
 
int main() {
    cs
    int n,ans=0;cin>>n;
    vector<int> v(n);
    vector<int> vv(n);
    vector<int> vvv(n-1);
    for(auto &i:v) cin>>i;
    for(auto &i:vv) cin>>i;
    for(auto &i:vvv) cin>>i;
    rep(i,n) {
        ans+=vv[v[i]-1];
        if(i&&v[i]-v[i-1]==1) ans+=vvv[v[i]-2];
    }
    cout<<ans;
}