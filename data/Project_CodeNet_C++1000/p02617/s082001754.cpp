#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).end()
#define pb push_back
#define pf push_front
#define fori(i, a, n) for(int i = a; i < n; ++i)
#define MAX(x) (*max_element(all(x)))
#define MIN(x) (*min_element(all(x)))
#define sortarr(a,n) sort(a, a+n)
#define sortvec(V) sort(all(V))

typedef vector<int> V;
typedef pair<int , int> pairi;
typedef set<int> seti;
typedef deque<int> deqi;

const int MOD = 1e9+7;
const int INF = 1e9+8;
const double pi = 3.14159265359;

void solve()
{
    int n;
    cin >> n;
    int ans = (n + 2) * (n + 1) * (n) / 6;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        if(x > y)   swap(x, y);
        --x, --y;
        ans -= ((x + 1) * (n - y));
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
}