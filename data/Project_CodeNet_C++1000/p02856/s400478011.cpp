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
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

int main(){
  int m; cin >> m;
  ll sum = 0LL;
  ll ans = 0LL;
  rep(i,m) {
    ll d,c; cin >> d >> c;
    sum += d*c;
    ans += c;
  }
  ans += (sum-1)/9 - 1;

  cout << ans << endl;
}
