#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

int main(){
  ll N, D, A;
  cin >> N >> D >> A;
  vector<Pll> xh(N);
  for(int i = 0; i < N; i++){
    ll x, h;
    cin >> x >> h;
    xh.at(i).first = x;
    xh.at(i).second = h;
  }
  sort(ALL(xh));
  vll X(N), HP(N);
  for(int i = 0; i < N; i++){
    X.at(i) = xh.at(i).first;
    HP.at(i) = xh.at(i).second;
  }
  vll imos(N, 0);
  ll ans = 0;
  for(int i = 0; i < N; i++){
    ll xx = xh.at(i).first;
    ll hh = xh.at(i).second;
    if(i > 0) imos.at(i) += imos.at(i-1);
    ll dd = hh - imos.at(i);

    if(dd <= 0) continue;

    ll num = (dd + A - 1) / A;
    ans += num;
    imos.at(i) += num * A;
    auto ite = upper_bound(ALL(X), xx + 2 * D);
    ll dist = distance(X.begin(), ite);
    if(dist < N) imos.at(dist) -= num * A;
  }
  cout<< ans << endl;
}
