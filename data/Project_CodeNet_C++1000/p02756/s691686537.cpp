#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  string s; cin >> s;
  int Q; cin >> Q;
  int parity = 0;
  string a = "", b = "";

  rep(q,Q){
    int t; cin >> t;
    if (t==1){
      (parity += 1) %= 2;
      swap(a,b);
      // reverse(all(a));
      // reverse(all(b));
    }
    else {
      int f; cin >> f;
      char c; cin >> c;
      if (f==1) {
        if (parity) a = a + c;
        else a = c + a;
      }
      else {
        if (parity) b = c + b;
        else b = b + c;
      }
    }
  }
  if (parity) {
    reverse(all(s));
    reverse(all(a));
    reverse(all(b));
  }
  cout << a+s+b << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

