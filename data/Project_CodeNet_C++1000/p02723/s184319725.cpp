#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main(){
  string s;
  cin >> s;

  if(s[2]==s[3]){
    if(s[4]==s[5]){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else{
    cout << "No" <<endl;
  }
  return 0;
}