#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const int inf = 1e9;
const ll INF = 1e18;
const db eps = 1e-10;
const db pi = acos(-1);

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ep emplace
#define mem(a) memset(a, 0, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))
#define PA cout << "pass\n"
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define TM cout << db(clock()) / CLOCKS_PER_SEC << '\n'

mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class T>inline void upmin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void upmax(T &x, T y) {x = x < y ? y : x;}

int n, x, T;

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    cin >> n >> x >> T;
    cout << (n + x - 1) / x * T << '\n';
    return 0;
}