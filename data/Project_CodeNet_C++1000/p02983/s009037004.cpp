#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int L, R;
  int ans = 2018;
  cin >> L >> R;
  bool flag = false;
  repi(i, L, R+1){
    repi(j, i+1, R+1){
      int l = i % 2019;
      int r = j % 2019;
      ans = min((l*r)%2019, ans);
      if (ans==0){
        flag=true;
        break;
      }
    }
    if (flag==true) break;
  }
  cout << ans << endl;
}