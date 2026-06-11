#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100010; //check the limits, dummy
 
vector<vi> graph;
ll fact[MX];
ll K;
ll ans = 1;
 
void dfs(int v, int p) 
{
    int countAvail = K - 1;
    if (p != -1) 
    countAvail=K-2;
    F0R(i, sz(graph[v])) 
    {
    	int nxt = graph[v][i];
        if (nxt == p) continue;
        if (countAvail <= 0) {/// means that the k is small bro
            ans = 0;
            return;
        }
        ans = ans * countAvail;
        countAvail--;
        ans = ans % MOD;
        dfs(nxt, v);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; F0R(i, N) {
        vi blank; graph.pb(blank);
    }
 
    cin >> K;
 
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }
 
    ans = K;
 
    dfs(0, -1);
    cout << ans << endl;
 
    return 0;
}