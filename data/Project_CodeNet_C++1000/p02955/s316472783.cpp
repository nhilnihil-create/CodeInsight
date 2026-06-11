#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

const int mod = 10000;

int main(){
  int n,k; cin >> n >> k;
  int sum = 0;
  vi a(n);
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }

  vi v;
  int ans;
  for(int i = 1; i*i <= sum; i++) {
    if(sum%i == 0){
      v.pb(i);
      v.pb(sum/i);
    }
  }

  sort(all(v),greater<int>());

  for(auto num : v) {
    vi na(n);
    int nsum = 0;
    rep(i,n){
      na[i] = a[i]%num;
      nsum += na[i];
    }

    sort(all(na),greater<int>());
    int cnt = 0;
    int nnsum = 0;
    rep(i,n) {
      cnt += num - na[i];
      nnsum += num;
      if(nnsum == nsum) break;
    }
    if(cnt <= k){
      ans = num;
      break;
    }
  }
  cout << ans << endl;
}
