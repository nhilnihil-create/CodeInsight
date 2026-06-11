#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n, m;
vector<pair<int, int>> vec;

bool check(int num) {
  stringstream stm;
  stm << num;
  string nt = stm.str();
  if (nt.size() != n) return false;
  bool ok  = true;
  rep(i, m) {
    if (nt[vec[i].first-1] != vec[i].second + '0') {
      ok = false;
    }
  }
  return ok;
}

int main() {

  cin >> n >> m;
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    vec.push_back(make_pair(s, c));
  }
  int ans = -1;
  rep(i, 1000) {
    if (check(i)) {
      cout << i << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}
// int main()
// {
//   int n, m;
//   cin >> n >> m;
//   vector<int> vec(n+1, 0);
//   rep(i, m) {
//     int s, c;
//     cin >> s >> c;
//     if (vec[s] != 0) {
//       if (vec[s] != c) {
//         cout << -1 << endl;
//         return 0;
//       }
//     } else {
//       vec[s] = c;
//     }    
//   }
//   ll ans = 0;
//   reps(i, 1, n+1) {
//     if (i == 0) break;

//     if (vec[i] == 0 && i == n) {
//       if (n > 1) {
//         cout << -1 << endl;
//         return 0;
//       } else {
//         cout << 0 << endl;
//         return 0;
//       }
//     } else {
//       ans += vec[i] * pow(10, n-i);
//     }
//   }
//   cout << ans << endl;
  
//   return 0;
// }