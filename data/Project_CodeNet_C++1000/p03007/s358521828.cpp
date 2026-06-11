#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

struct Node {
  ll left;
  ll right;
  ll value; // 葉でなければ-1
};

const ll NONE = 10000000;
Node node[200000];

vector<PLL> ans;

ll f(ll i) {
  if (node[i].value != NONE)
    return node[i].value;

  ll x = f(node[i].left);
  ll y = f(node[i].right);
  ans.push_back({x,y});
  return x-y;
}

signed main() {
  ll N;
  cin >> N;
  vector<ll> B(N);
  rep(i,N) {
    cin >> B[i];
  }


  sort(begin(B), end(B));
  vector<ll> A;
  A.push_back(B[N-1]);
  A.push_back(B[0]);
  for (ll i=1; i<N-1; i++) {
    A.push_back(B[i]);
  }

  node[0] = Node{1, 2, NONE};
  node[1] = Node{0, 0, A[0]}; // +
  node[2] = Node{0, 0, A[1]}; // -

  ll root = 0, nNode = 3;

  for (ll i=2; i<N; i++) {
    if (A[i] < 0) {
      // 直下にくっつけた方が有利
      ll n1 = nNode;
      ll n2 = nNode + 1;

      node[n1].left  = root;
      node[n1].right = n2;
      node[n1].value = NONE;

      node[n2].left  = 0;
      node[n2].right = 0;
      node[n2].value = A[i];

      root = n1;
      nNode += 2;
    } else {
      // 2個下にくっつけた方が有利
      ll n1 = nNode;
      ll n2 = nNode + 1;

      node[n1].left = node[root].right;
      node[n1].right = n2;
      node[n1].value = NONE;

      node[n2].left = 0;
      node[n2].right = 0;
      node[n2].value = A[i];


      node[root].left;
      node[root].right = n1;
      node[root].value;

      root;
      nNode += 2;
    }
  }

  f(root);
  cout << ans[ans.size()-1].first - ans[ans.size()-1].second << endl;
  for (auto e: ans) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}

