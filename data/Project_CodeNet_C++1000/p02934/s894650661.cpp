#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 0x3f3f3f3f; constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define db(x) { cerr << #x << " = " << x << endl; }
template <typename T> void _dbarr(T* a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
template <typename T> void _dbarr(vector<T> a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
#define dbarr(x, n) {cerr << #x << ": "; _dbarr((x),(n));}
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fs first
#define sn second

int main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ld v = 0;
    for(int i = 0; i < n; i++)
    {
        v += (1.0/a[i]);
    }
    cout << fixed << setprecision(7) << 1.0 / v << "\n";
}
