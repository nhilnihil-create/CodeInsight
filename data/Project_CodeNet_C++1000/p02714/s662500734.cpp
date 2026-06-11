#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  ll r=0,g=0,b=0;
  rep(i,n){
      char c=s[i];
      if(c=='R') r++;
      else if(c=='G') g++;
      else b++;
      
  }
  ll cnt=0;
  rep(i,n)for(int j=i+1;j<=n;j++){
      int k=2*j-i;
      if(k<n)if(s[i]!=s[j]&&s[j]!=s[k]&&s[k]!=s[i]) cnt++;
  }
  cout << r*g*b-cnt << endl;
}