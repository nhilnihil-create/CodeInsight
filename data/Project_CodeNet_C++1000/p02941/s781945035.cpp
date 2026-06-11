#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

random_device rd;
mt19937 rng(rd());

template<class T>
T randomize(T mod)
{
	return uniform_int_distribution<T>(0, mod - 1)(rng);
}

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 200013;

int N;
int A[MAXN], B[MAXN];
ll ans;
priority_queue<pii> pq;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> A[i];
    }
    FOR(i, 0, N)
    {
        cin >> B[i];
        if (B[i] < A[i])
        {
            cout << "-1\n";
            return 0;
        }
        if (B[i] != A[i])
        {
            pq.push({B[i], i});
        }
    }
    while(!pq.empty())
    {
        int d = pq.top().fi, u = pq.top().se; pq.pop();
        int sum = B[(u == 0) ? N - 1 : u - 1] + B[(u == N - 1) ? 0 : u + 1];
        // cerr << d << ' ' << A[u] << ' ' << u << ' ' << sum << endl;
        if (d % sum <= A[u] || d < sum)
        {
            if ((A[u] - d) % sum)
            {
                cout << "-1\n";
                return 0;
            }
            ans += (d - A[u]) / sum;
            B[u] = A[u];
        }
        else
        {
            ans += (d / sum);
            B[u] = d % sum;
            pq.push({B[u], u});
        }
    }
    cout << ans << '\n';
    return 0;
    //find the largest B[i]

}
