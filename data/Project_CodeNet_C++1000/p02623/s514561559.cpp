/*Be patient && calm!
All our dreams can come true, if we have the courage to pursue them.
The secret of getting ahead is getting started.
It is hard to beat a person who never gives up.
First, solve the problem. Then, write the code.
Fix the cause, not the symptom.
Simplicity is the soul of efficiency.
Make it work, make it right, make it fast.*/
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;
#define mod 1000000007
#define N 100005
#define ll long long
#define ull unsigned long long
#define loop1(i, j, k, step) for (int i = j; i < k; i += step)
#define loop(i, j, k) for (int i = j; i < k; i++)
#define rloop1(i, j, k, step) for (int i = j; i >= k; i -= step)
#define rloop(i, j, k) for (int i = j; i >= k; i--)
#define rep(i, k) for (int i = (0); i < (k); i++)
#define rrep(i, k) for (int i = k - 1; i >= 0; i--)
#define forall(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define lin "\n"
#define Max (int)INT_MAX
#define Min (int)INT_MIN
#define MEM(a, b) memset(a, (b), sizeof(a))
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)
#define PI 2 * acos(0.0)
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

// bool sortinrev(const pair<int, int> &a,
//                const pair<int, int> &b)
// {
//     return (a.first > b.first);
// }
// bool spOrder(const pair<int, int> &a,
//              const pair<int, int> &b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first > b.first;
//  }
int a[2 * N];
queue<int> b;
ll Sum[2 * N];

void pSum(int n) {
    Sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        Sum[i] = Sum[i - 1] + a[i];
    }

}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll aSum = 0, bSum = 0;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        int x;
        cin >> x;
        bSum += x;
        b.push(x);
    }
    pSum(n);
    int pos = 1;
    int ans = distance(Sum, upper_bound(Sum, Sum + n, k));
    while (!b.empty() && k > 0) {
        k -= b.front();
        int x = distance(Sum, upper_bound(Sum, Sum + n, k));
        if (k >= 0)
            ans = max(ans, x + pos);
        b.pop();
        pos++;
    }
    cout << ans << lin;
}

int main() {
    // auto start = clock();
    fast_io;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    // auto stop = clock();
    // cerr << "time taken:" << double(stop - start) / double(CLOCKS_PER_SEC) << " s" << endl;
    return 0;
}