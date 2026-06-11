#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s, t;
  cin >> s >> t;

  int ans = t.size();

  for(int i=0; i<=s.size()-t.size(); ++i){
    int cnt = 0;
    for(int j=0; j<t.size(); ++j){
      if(t[j] != s[i+j]) cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
}