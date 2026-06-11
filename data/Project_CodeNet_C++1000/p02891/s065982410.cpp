#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> t;
  ll k;
  cin >> k;
  s=t;
  if(s==string(s.size(),s[0])) {
    cout << s.size()*k/2 << endl;
    return 0;
  }
  ll ans=0;
  for(int i=1; s[i]!='\0'; i++) {
    if(s[i]==s[i-1]) {
      ans++;
      s[i]='*';
    }
  }
  ans*=k;
  int n1=1, n2=1;
  for(int i=1; i<t.size(); i++) {
    if(t[0]==t[i]) n1++;
    else break;
  }
  for(int i=t.size()-2; i>=0; i--) {
    if(t.back()==t[i]) n2++;
    else break;
  }
  if(n1%2==1&&n2%2==1&&t[0]==t.back()) ans += k-1;

  cout << ans << endl;
}
