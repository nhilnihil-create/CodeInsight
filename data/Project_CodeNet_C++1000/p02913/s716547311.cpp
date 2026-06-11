#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 2e5 + 5;

int z_function(string s){
  int n = s.length();
  vector < int > z(n, 0);
  int l = 0, r = 0, ans = 0;
  for(int i = 1; i < n; i++){
    if(r >= i) z[i] = min(z[i - l], r - i + 1);
    while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
    if(i + z[i] - 1 > r){
      l = i;
      r = i + z[i] - 1;
    }
    ans = max(ans, min(z[i], i));
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, z_function(s.substr(i, n - i)));
  }

  cout << ans << '\n';
}
