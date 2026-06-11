#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(a) begin(a),end(a)
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define sz(x) ((int)x.size())
#define ins insert
#define rep(i,l,u) for(int i=l;i<=u;++i)
#define reb(i,l,u) for(int i=l;i>=u;--i)
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
const int inf=1e18;
main(){
    int n,m;
    cin>>n>>m;
    int l=2*n;
    int r=4*n;
    if(m>=l&&m<=r){
        if((r-m)%2)puts("No");
        else puts("Yes");
    }
    else puts("No");
}
