#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;
ll n;
vector<char> c(10);

void dfs(ll k,ll memo){
    if(k == n){
        rep(i,0,n){
            cout << c[i];
        }
        cout << endl;
        return;
    }

    rep(i,0,memo+1){
        c[k] = 'a' + i;
        dfs(k+1,max(memo,i+1));
    }

    return;
}

signed main(){
    cin >> n;

    c[0] = 'a';
    dfs(1,1);

    return 0;
}
