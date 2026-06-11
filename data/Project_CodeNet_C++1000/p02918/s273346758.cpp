#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int cnt = 0;
  rep(i,n-1){
    if(s[i] == s[i+1]) cnt++;
  }

  int ans = min(cnt+2*k, n-1);
  cout << ans << endl;
}
