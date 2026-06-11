#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size();

  int cnt = 0;
  for(int i=0; i<n; ++i){
    if(s[i] != t[i]) cnt++;
  }
  cout << cnt;
}