#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  string s;
  int q;
  cin >>s >>q;
  int F = 0;
  vector<string> a(2, "");
  rep(i,q){
    int t; cin >>t;
    if(t==1) F = 1-F;
    else {
      int f; char c;
      cin >>f >>c;
      a[(F+f-1)%2]+=c;
    }
  }
  reverse(a[F].begin(), a[F].end());
  if(F==1) reverse(s.begin(), s.end());
  cout << a[F] << s << a[1-F] << endl;
  return 0;
}