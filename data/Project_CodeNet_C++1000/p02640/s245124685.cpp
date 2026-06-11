#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i <= (int)(n); i++)

int main(){
  int X, Y;
  cin >> X >> Y;
  bool flg = false;
  int c=X, t;
  
  rep(i,X){
    if(i * 2 + (X-i) *4 ==Y){
     flg = true;
      break;
    }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
}
