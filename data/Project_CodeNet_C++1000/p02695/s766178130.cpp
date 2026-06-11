#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
vector<int> p,a,b,c,d;
ll dfs(int depth, const int n, const int m, const int q, int start){
    ll ans = 0;
    if(depth == n){
        for(int i=0; i<q; i++){
            if(p[b[i]-1]-p[a[i]-1]==c[i]){
                ans+=d[i];
            }
        }
        return ans;
    }else{
        for(int i=start; i<=m; i++){
            p[depth] = i;
            ans = max(ans,dfs(depth+1,n,m,q,i));
        }
    }
    return ans;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    p.resize(n);
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i=0; i<q; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    ll ans = 0;
    ans = dfs(0,n,m,q,1);
    cout<<ans<<endl;
    
}