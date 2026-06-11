#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  string s;cin >> s;
  rep(i,s.length()){
    if((i+1)%2 != 0){ //奇数
      if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D'){
        cout << "No" << endl;
        return 0;
      }
    } else { //偶数
      if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
