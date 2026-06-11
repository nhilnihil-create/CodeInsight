#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;

//typedef
//-------------------------#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s)
{
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}
inline int readInt()
{
    int x;
    scanf("%d", &x);
    return x;
}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a) * (a))
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

//repetition
//------------------------------------------
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define MOD 1000000007

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;

#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const int INF = 2147483647;

const int dxy[5] = {-1, 0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    vector<vector<int>> G(100010);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }

    int S, T;
    cin >> S >> T;
    S--;
    T--;

    vector<vector<int>> d(N, vector<int>(5, (1 << 30)));
    d[S][0] = 0;

    queue<pair<int, int>> q;
    q.push({S, 0});

    while (q.size())
    {
        auto p = q.front();
        q.pop();

        int v = p.first, s = p.second;

        for (int i = 0; i < G[v].size(); i++)
        {

            int u = G[v][i];
            if (d[u][(s + 1) % 3] == (1 << 30))
            {
                if (s + 1 == 3)
                {
                    d[u][0] = d[v][s] + 1;
                }
                else
                {
                    d[u][s + 1] = d[v][s];
                }
                q.push({u, (s + 1) % 3});
            }
        }
    }
    if (d[T][0] == 1 << 30)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[T][0] << endl;
    }
    return 0;
}
