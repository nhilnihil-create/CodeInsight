#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int now;
    cin >> now;
    a[now]++;
  }

  bool ok = true;
  if(a.size() > 3) ok = false;
  if(a.size() == 1){
    if(!a.count(0)) ok = false;
  }
  if(a.size() == 2){
    if(!a.count(0)) ok = false;
    else{
      if(a.at(0) == n / 3 && n % 3 == 0) ok = true;
      else ok = false;
    }
  }
  if(a.size() == 3){
    queue<int> k;
    for(auto now : a){
      if(now.second != n/3) ok = false;
      if(n%3 != 0) ok = false;
      k.push(now.first);
    }
    int x, y, z;
    x = k.front();
    k.pop();
    y = k.front();
    k.pop();
    z = k.front();
    k.pop();
    int ans = x ^ y ^ z;
    if(ans != 0) ok = false;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}

// 001
// 011
// 010

// 001
// 000
// 001
