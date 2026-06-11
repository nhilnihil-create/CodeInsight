#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

bool isKaibun(string);

int main(){
  string s;
  cin >> s;
  
  string str1,str2;
  int n = s.size();
  str1 = s.substr(0,(n-1)/2);
  str2 = s.substr((n+3)/2-1);
  
  if(isKaibun(s) && isKaibun(str1) && isKaibun(str2)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

bool isKaibun(string s){
  string t(s.rbegin(),s.rend());
  if(s == t){
    return true;
  }else{
    return false;
  }
}