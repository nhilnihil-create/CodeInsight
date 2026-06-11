#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  int q;
  cin >> s >> q;
  vector<string> a(2, "");
  int f=0;
  rep(i, q){
    int t;
    cin >> t;
    if(t == 1) f = 1 - f;
    else{
      int f_;
      char c;
      cin >> f_ >> c;
      a[(f+f_-1)%2] += c;
    }
  }
  reverse(a[f].begin(), a[f].end());
  if(f == 1) reverse(s.begin(), s.end());
  cout << a[f] << s << a[1-f] << endl;
  return 0;
}
