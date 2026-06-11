#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
const ll INF = 1LL << 58;
const ll MOD = 1000000007;
typedef vector<pii> vpii;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
#define AAA 100010
typedef struct
{
    int parent;
    queue<pair<int, int>> qu;
} node;

int ans[AAA];
int m = 0;
node A[AAA];

void solve(int i, int color)
{
    while (A[i].qu.size() > 0)
    {
        pair<int, int> now = A[i].qu.front();
        A[i].qu.pop();

        int next = now.first;
        int idx = now.second;
        ans[idx] = color + 1;
        color++;
        color %= m;
        solve(next, color);
    }
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    REP(i, N - 1)
    {
        ans[i] = -1;
    }
    REP(i, N)
    {
        A[i + 1].parent = -1;
    }

    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        A[a].qu.push(make_pair(b, i));
        A[b].parent = a;
    }
    m = 0;
    REP(i, N)
    {
        int tmp = 0;
        tmp = A[i + 1].qu.size();
        if (A[i + 1].parent != -1)
            tmp++;
        m = max(m, tmp);
    }

    int start = 1;
    while (true)
    {
        int tmp = A[start].parent;
        if (tmp == -1)
        {
            break;
        }
        start = tmp;
    }
    solve(start, 0);
    cout << m << endl;
    REP(i, N - 1)
    {
        cout << ans[i] << endl;
    }

    return 0;
}