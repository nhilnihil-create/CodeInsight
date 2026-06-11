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

//ベクトルがすっかり抜けていた

int main(){
  ll S;
  cin >> S;

  ll x1 = 0LL, y1 = 0LL;
  ll x2 = 1000000000LL, y2 = 1LL;
  ll x3 = 1000000000LL - S % 1000000000LL;
  ll y3 = S / 1000000000LL + 1;
  if(S % 1000000000LL == 0LL){
    x3 = 0LL;
    y3 = S / 1000000000LL;
  }
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}