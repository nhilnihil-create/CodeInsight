#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  int x;
  cin >> x;
  int n = 100005;
  
  vector<bool> a(n);
  rep(i,n) a[i] = 1;

    rep(i,n){
      if(i == 0 || i == 1) continue;
      for(int j = i*2; j < n; j += i) {
      if(i < 4) continue;
      a[j] = 0;
    }
  }
  
  rep(i,n){
    if(i < x) continue;
    if(a[i] == 1){
      cout << i << endl;
      return 0;
    }
  }
}
