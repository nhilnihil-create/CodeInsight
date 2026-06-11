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
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  map<int,int> m;
  rep(i, N) m[a[i]]++;
  
  if(m.size() == 3){
    auto b = m.begin();
    auto c = next(b, 1);
    auto d = next(b, 2);
    int bn = (*b).second;
    int cn = (*c).second;
    int dn = (*d).second;
    int bb = (*b).first;
    int cc = (*c).first;
    int dd = (*d).first;
    if(bn == cn && cn == dn && (bb^cc) == dd) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(m[0] > 0) {
    if(m.size() == 1) {
      cout << "Yes" << endl;
      return 0;
    }
    if(m.size() == 2) {
      auto b = next(m.begin(), 1);
      int bn = (*b).second;
      int bb = (*b).first;
      if(bn == 2*m[0]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;

    

}