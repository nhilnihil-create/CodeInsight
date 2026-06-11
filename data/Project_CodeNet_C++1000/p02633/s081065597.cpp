//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), x.end()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x; cin >> x;
  cout << 360 / __gcd(x, 360) << endl;
  return 0;
}
