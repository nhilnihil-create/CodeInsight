#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll
#define INF 1e16
#define mod 1000000007
int main(){
    ll n,a;
    cin>>n;
    vector<ll> c(n);
    vector<ll> d(n+1,0);
    rep(i,n) {
        cin>>a;
        a--;
        c[a]++;
        d[c[a]]++;
    }
    vector<ll> S(n+1,0);
    for (int i = 1; i < n+1; ++i) S[i] = S[i-1] + d[i];
    for (long long K = 1; K <= n; ++K) {
        long long low = 0, high = n+1;
        while (high - low > 1) {
            long long x = (low + high) / 2;
            if (S[x] >= K * x) low = x;
            else high = x;
        }
        cout << low << endl;
    }    
    return 0;
}