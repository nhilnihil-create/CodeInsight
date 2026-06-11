#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main(){FIN
    queue<ll> que;
    ll n;cin>>n;
    FOR(i,1,9) que.push(i);
    ll now=0;
    REP(i,n){
        now = que.front();
        que.pop();
        if (now%10==0){
            que.push(now*10+0);
            que.push(now*10+1);
        }
        else if(now%10==9){
            que.push(now*10+8);
            que.push(now*10+9);
        }
        else{
            ll matu = now%10;
            que.push(now*10+matu-1);
            que.push(now*10+matu+0);
            que.push(now*10+matu+1);
        }
    }

    cout<<now<<endl;
    
    return 0;
}
