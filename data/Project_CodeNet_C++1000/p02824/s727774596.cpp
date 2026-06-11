#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const int inf = 1e9;
const ll INF = 1e18;
const db eps = 1e-10;

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

int n, m, v, p;
const int maxn = 1e5 + 233;
int a[maxn];
ll sum[maxn];

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> v >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(i <= p) {
            res++;
            continue;
        }
        if(a[p] > a[i] + m) continue;
        ll tmp = 1ll * m * v - 1ll * (n - i + 1) * m - 1ll * (p - 1) * m;
        if(tmp <= 0){
            if(a[i] + m >= a[p]) res++;
            continue;
        }
        if(1ll * (i - p) * (a[i] + m) - (sum[i - 1] - sum[p - 1]) >= tmp){
            if(a[p] > a[i] + m) continue;
            res++;
            continue;
        }
    }
    cout << res << '\n';
    return 0;
}