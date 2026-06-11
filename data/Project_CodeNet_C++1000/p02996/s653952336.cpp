#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  vector<pair<int,int>> v(N);
  rep(i, N) {
    int a, b; cin >> a >> b;
    v[i] = make_pair(b, a);
  }
  sort(all(v));
  
  int t = 0;
  for(auto p : v) {
    t += p.second;
    if(t > p.first) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
        

}
