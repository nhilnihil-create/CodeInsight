#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;


int main(){
  string s;
  cin >> s;

  int n = sz(s)+1;
  vector<int> a(n);
  rep(i, n-1){
    if(s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);
  }
  for(int i = n-1; i >=0; i--){
    if(s[i] == '>') a[i] = max(a[i], a[i+1]+1);
  }

  ll ans = 0;
  for(auto i : a){
    ans += i;
  }
  cout << ans << endl;
  
}
