#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;
  rep(i,n-2){
    if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
  }

  cout << ans << endl;
  return 0;
}
