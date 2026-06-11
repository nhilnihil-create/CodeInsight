#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;}
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

const long long BFSMAX = 101010; // Set
vllvll bfsGraph(BFSMAX);
vll bfsdist(BFSMAX);
vector<bool> seen(BFSMAX);
map<pll, ll> colors;
ll diff = 0;

template<class T>
void bfs(T start)
{
    fill(bfsdist.begin(), bfsdist.end(), inf);
    bfsdist[start] = 0;
    fill(seen.begin(), seen.end(), false);

    queue<T> q;
    q.push(start);

    vll prevc(BFSMAX);
    while (! q.empty()) {
    auto now = q.front(); q.pop();
        ll c = 0;
        for (auto adj : bfsGraph[now]) {
            if (bfsdist[adj] == inf) {
                bfsdist[adj] = bfsdist[now] + 1;
                ++c;
                if (c == prevc[now]) ++c;
                colors[pll{now, adj}] = c;
                
                q.push(adj);
                prevc[adj] = c;
            }
        }
    }
}

// Prepare for `bfsGraph`
int main()
{
        ll N;
        cin >> N;
        vll e1(N), e2(N);
        rep(i, 0, N-1) {
                ll a, b;
                cin >> a >> b;
                bfsGraph[a].push_back(b);
                bfsGraph[b].push_back(a);
                e1[i] = a;
                e2[i] = b;
        }

        bfs(1);

        vll ans;
        rep(i, 0, N-1) {
                ans.push_back(max(colors[pll{e1[i], e2[i]}], colors[pll{e2[i], e1[i]}]));
        }
        cout << *max_element(all(ans)) << endl;
        rep(i, 0, N-1) {
                cout << ans[i] << endl;
        }
}
