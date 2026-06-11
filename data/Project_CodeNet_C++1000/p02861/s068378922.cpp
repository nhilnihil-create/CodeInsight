#include <bits/stdc++.h>
using namespace std;
// define
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (((a)%mod) * ((b)%mod)) % mod
#define rollcall cout << "I'm Sucu." << endl;
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define fi first
#define se second
// typedef
typedef complex<double> Point;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;
const int mod = 1e9+7;
// int sum = accumulate(a, a+n, 0LL);
// int mx = max_element(a, a+n);
// int mn = min_element(a, a+n);
// int cnt = count(a, a+n, k);

int N;
int x[10], y[10];
 
double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}
 
void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    double sum = 0.0;
    vector<int> v(N);
    for(int i = 0; i < N; i++) v[i] = i + 1;
    do {
        for(int i = 0; i < N - 1; i++) sum += dist(v[i], v[i+1]);
    } while(next_permutation(v.begin(), v.end()));
    int Factorial = 1;
    for(int i = 2; i <= N; i++) Factorial *= i;
    cout << fixed << setprecision(10) << sum / Factorial << endl;
    return;
}
 
signed main() {
    solve();
    return 0;
}