#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<char> s(n+1);
  for(int i=1; i<=n; i++) cin >> s[i];
  ll r=0, b=0, g=0;
  for(int i=1; i<=n; i++){
    if(s[i] == 'R') r++;
    if(s[i] == 'B') b++;
    if(s[i] == 'G') g++;
  }
  ll ans = r*b*g;
  for(int i=1; i<=n; i++)for(int j=i+1; j<=n; j++){
    int k = 2*j-i;
    if(k <= n){
      if(s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) ans--; 
    }
  }
  cout << ans << endl;
}
