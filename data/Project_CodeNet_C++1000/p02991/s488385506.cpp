#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

int n, m, s, t;
VVI g;
vector<set<int>> ng;

int dijkstra()
{
    deque<pair<int, int>> dq;
    VI done(n * 3, -3);
    dq.push_back({s, 0});
    done[s] = 0;
    while (!dq.empty()) {
        int cplace = dq.front().e1;
        int ctime = dq.front().e2;
        dq.pop_front();
        //cout<<cplace/3<<"_"<<cplace%3<<" "<<ctime/3<<"_"<<ctime%3<<endl;

        REPITR(itr, ng[cplace]) {
            if (done[*itr] == -3) {
                done[*itr] = ctime + 1;
                dq.push_back({*itr, ctime + 1});

                //if (*itr == t)
                    //break;
            }
        }
    }
    //REP(i, 3 * n) cout<<done[i]<<" "; nextline;

    return done[t] / 3;
}

int main()
{
    cin>>n>>m;
    g.resize(n); ng.resize(n * 3);
    REP(i,m) {
        int u, v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
    }
    cin>>s>>t;
    s--; t--;
    s *= 3; t *= 3;

    //create new graph
    REP(i,n) {
        REPALL(j,g[i]) {
            ng[i * 3].insert(g[i][j] * 3 + 1);
            ng[i * 3 + 1].insert(g[i][j] * 3 + 2);
            ng[i * 3 + 2].insert(g[i][j] * 3);
        }
    }

    cout<<dijkstra()<<endl;

    return 0;
}
