//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<long long ,long long >
typedef long long ll;
ll memo[1005][10005],h,n;
pii arr[1005]; 
ll f(int idx,int x){
    if(idx > n) return 1e15;
    if(x<=0 ) return 0;
    if(memo[idx][x]!=-1 ) return memo[idx][x];
    ll cnt=min(f(idx,x-arr[idx].fi) + arr[idx].se,f(idx+1,x) );
    return memo[idx][x] = cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].fi >> arr[i].se;
    }
    memset(memo,-1,sizeof(memo));
    cout<<f(1,h)<<endl;
}