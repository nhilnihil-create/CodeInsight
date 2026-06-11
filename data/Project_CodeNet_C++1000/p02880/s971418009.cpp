#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  bool ans = false;
  rep(i, 9){
    rep(j, 9){
      if(n==(i+1)*(j+1)) ans = true;
    }
  }
  
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    
  return 0;
}
