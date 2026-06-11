#include<bits/stdc++.h>
using namespace std;

int main(){
  int a;
  string s;
  cin >> a >> s;
  if( a % 2 != 0 ) cout << "No" << endl;
  else{
    bool flag = true;
    for(int i = 0; i < a/2; i++){
      if( s[i] != s[i+a/2] ) {
        flag = false;
      }
    }
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}