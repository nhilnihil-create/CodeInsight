#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000000;

//long long
using ll = long long;

const long long lINF= ll(1e18) + 5;

//出力系
#define print(x) cout << x << endl
#define prints(x) cout << fixed << setprecision(10) << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

// a = max(a, b), a = min(a, b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

/**
 *    author:  tourist
 *    created: 14.07.2019 15:46:31       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  if (cnt[0] == n) {
    yes;
    return 0;
  }
  if (n % 3 != 0) {
    no;
    return 0;
  }
  vector<int> all;
  for (auto& p : cnt) {
    for (int i = 0; i < p.second / (n / 3); i++) {
      all.push_back(p.first);
    }
  }
  if (all.size() == 3 && (all[0] ^ all[1] ^ all[2]) == 0) {
    yes;
  } else {
    no;
  }
  return 0;
}
