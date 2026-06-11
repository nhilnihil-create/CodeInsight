#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;
 
int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  bool dance = true;
  rep(i,n){
    if(i%2==0){
       if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D'){
         dance = false;
       }
    }
    if(i%2!=0){
      if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D'){
        dance = false;
      }
    }
  }
  if(dance){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}