#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  string S; cin >> S;
  S = "." + S;
  S += "###";
  
  vector<bool> a(N+3, false), b(N+3, false);
  a[A] = true; b[B] = true;
  
  rep_(i, B, D) {
    if(b[i]) {
      if(S[i+1] == '.') b[i+1] = true;
      if(S[i+2] == '.') b[i+2] = true;
    }
  }
  
  vector<int> over(0);
  rep(i, D) if(b[i] && b[i+1] && b[i+2]) over.push_back(i);
  b[D+1] = false;
  
  rep_(i, A, N+1) {
    if(a[i]) {
      if(S[i+1] == '.') a[i+1] = true;
      if(S[i+2] == '.') a[i+2] = true;
    }
  }
  
  bool ov = false;
  for(int i : over) if(a[i] && a[i+1] && a[i+2]) ov = true;
  if(a[B-1] && a[B] && a[B+1]) ov = true;
  
  if(!ov) {
    rep_(i, D, N+1) a[i] = false;
  }
  
  //rep(i, N+1) cout << a[i]; cout << endl;
  //rep(i, N+1) cout << b[i]; cout << endl;
  
  if(a[C] && b[D]) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  

  
}
