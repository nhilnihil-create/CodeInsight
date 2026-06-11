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

struct SegmentTree {
  int siz;
  vector<ll> node;
  SegmentTree(int n, ll init) {
    siz = 1;
    while (siz < n) siz <<= 1;
    node.assign(2 * siz, init);
  }

  void update(int k, ll x) {
    k += siz - 1;
    node[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = max(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = siz;
    if (r <= a || b <= l) return -LINF;
    if (a <= l && r <= b) return node[k];
    ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a[ohara], b[ohara], c, d, tmp, m, h, w, x, y;
ll k, q, f[ohara], bit[ohara], bits[ohara];
set<ll> st;
U_MAP mp;
ll nowco[ohara];

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(ll i, ll x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

ll sums(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bits[i];
    i -= i & -i;
  }
  return s;
}

void adds(ll i, ll x) {
  while (i <= n) {
    bits[i] += x;
    i += i & -i;
  }
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rep(i, n) cin >> a[i], b[a[i]]++;

  rep(i, n) {
    if (b[a[i]] == 0) continue;
    add(b[a[i]], b[a[i]]);
    adds(b[a[i]], 1);
    cnt++;
    b[a[i]] = 0;
  }

  rrep(i, 1, n + 1) {
    ll cost;
    cost = cnt * i;
    cost = cost - (sums(i) * i - sum(i));
    cost /= i;
    f[i] = cost;
    // cout << f[i] << " " << i << "\n";
  }

  SegmentTree tree(ohara, -LINF);

  rrep(i, 1, n + 1) {
    nowco[f[i]] = max(nowco[f[i]], f[i]);
    tree.update(nowco[f[i]], i);
  }

  rep(i, n) {
    ans = tree.query(i + 1, ohara);
    cout << (ans == -LINF ? 0 : ans) << "\n";
  }
  return 0;
}