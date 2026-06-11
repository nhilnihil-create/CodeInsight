#include<atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1LL<<60;
const int INF = 1LL<<17;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};

int main(){
    ll n, m;    cin >> n >> m;
    dsu tree(n);
    rep(i, m){
        ll a, b;    cin >> a >> b;
        a--, b--;
        tree.merge(a, b);
    }
    set<ll> st;
    rep(i, n) st.insert(tree.leader(i));
    cout << st.size()-1 << endl;
}
