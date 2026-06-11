#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll n; cin >> n;
  
  string ans = "";
  while(n){
    n--;
    char tmp = 'a';
    tmp += (n%26);
    n /= 26;
    ans = tmp+ans;
  }
  cout << ans << endl;
    
  return 0;
}
