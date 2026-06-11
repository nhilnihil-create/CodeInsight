#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a[ohara], b[ohara], c, d, tmp, m, h, w, x, y, sum, k, q;
ll di_sum;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) {
    di_sum += a[i] * b[i];
    sum += b[i];
  }
  ans = di_sum / 9;
  if (di_sum % 9 == 0) ans--;
  Cout(ans + sum - 1);
  return 0;
}