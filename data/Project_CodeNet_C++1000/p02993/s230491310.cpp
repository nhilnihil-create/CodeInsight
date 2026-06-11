#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  string s, ans="Good";
  cin >> s;
  rep(i, 3){
    if(s[i]==s[i+1]){
      ans="Bad";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}