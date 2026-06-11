// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define BP(x) __builtin_popcountll(x)
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

const int INF = 1e18 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int L = 62;

int basis[L], bsize;

void prepare(int mask) {
  for(int i = 0; i < L; i++) {
    if((mask&(1ll<<i))) {
      if(!basis[i]) {
        basis[i] = mask; bsize++;
        return;
      }
      mask ^= basis[i];
    }
  }
}

bool ok(int mask) {
  for(int i = 0; i < L; i++) {
    if((mask&(1ll<<i))) {
      if(!basis[i]) {
        return 0;
      }
      mask ^= basis[i];
    }
  }
  return 1;
}

void solve() {
    memset(basis,0, sizeof(basis));
    int n; cin >> n;
    int data[n+5];
    for(int i = 1; i <= n; i++) {
      cin >> data[i];
    }
    string s; cin >> s;
    reverse(all(s));
    reverse(data+1, data+n+1);
    for(int i = 0; i < sz(s); i++) {
      if(s[i] == '0') {
        prepare(data[i+1]);
      } else {
        if(!ok(data[i+1])) {
          cout << "1\n"; return;
        }
      }
    }
    cout << "0\n";
}

signed main() {   
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
   int t = 1;  cin >> t;
   for(int i = 1; i <= t; i++) {
     solve();
  }
}    
