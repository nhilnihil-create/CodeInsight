#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string ans="No";
  rep(i, 9){
    rep(j, 9){
      if((i+1)*(j+1)==n){
        ans="Yes";
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}