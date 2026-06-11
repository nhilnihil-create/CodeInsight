#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  int ans;

  if(s=="SUN") ans = 7;
  else if(s=="MON") ans = 6;
  else if(s=="TUE") ans = 5;
  else if(s=="WED") ans = 4;
  else if(s=="THU") ans = 3;
  else if(s=="FRI") ans = 2;
  else if(s=="SAT") ans = 1;

  cout << ans << endl;
  
  return 0;
}
