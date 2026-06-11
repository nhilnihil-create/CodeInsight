 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n;
  string s;
  cin >> n >> s;
  string s1,s2;
  rep(i,n/2){
    char a = s[i];
    s1 += a;
  }
  for(ll i = n/2; i<n; i++){
    char a = s[i];
    s2 += a;
  }
  if(s1==s2) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}