#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string p;
  string q;
  char c;
  rep(i, n){
    cin >> c;
    p += c;
  }
  rep(i, n){
    cin >> c;
    q += c;
  }

  string s;
  rep(i, n) s += ((i + 1) + '0');
  vector<string> vs;
  do {
    vs.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  sort(vs.begin(), vs.end());
  auto fact = [](int k) {
    int f = 1;
    rep(i, k){
      f *= (i + 1);
    }
    return f;
  };
  int a, b;
  rep(i, fact(n)){
    if (vs[i] == p) a = i;
    if (vs[i] == q) b = i;
  }
  cout << abs(a - b) << endl;
  return 0;
}