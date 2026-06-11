#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size();

  int ans = 0;
  bool flag = false;
  int num = 0;

  while(num<n){
    if(num == n-2 && s[num] == s[num+1]){
      ans++;
      break;
    }
    if(flag && s[num] == s[num-1]){
      ans++;
      num+=2;
      flag = false;
    }
    else{
      ans++;
      num++;
      flag = true;
    }
  }
  cout << ans << endl;

}
