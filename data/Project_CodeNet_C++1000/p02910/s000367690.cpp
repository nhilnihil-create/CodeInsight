#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  bool flag = true;
  rep(i,s.size()){
    if(i%2==0 && s[i] == 'L') flag = false;
    if(i%2!=0 && s[i] == 'R') flag = false;
  }  

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
