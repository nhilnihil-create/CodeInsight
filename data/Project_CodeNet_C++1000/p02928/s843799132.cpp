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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                cnt1++;
            }
        }
        for (int j = i; j < N; j++)
        {
            if (A[i] > A[j])
            {
                cnt2++;
            }
        }

        ll t1 = (K * (K + 1) / 2) % MOD * cnt2;
        t1 %= MOD;
        ll t2 = (K * (K - 1) / 2) % MOD * cnt1;
        t2 %= MOD;

        ans += (t1 + t2) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
