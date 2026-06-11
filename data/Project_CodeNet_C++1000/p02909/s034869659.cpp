#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  string ans;
  
  if(s=="Sunny") ans = "Cloudy";
  else if(s=="Cloudy") ans = "Rainy";
  else if(s=="Rainy") ans = "Sunny";

  cout << ans << endl;
  
  return 0;
}
