#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> ans(1e5);
  ll count=0;
  reverse(s.begin(),s.end());
  s=s+'0';
  ll temp=0;
  while(temp<n) {
    ll go=k;
    bool flag=false;
    while(1) {
      if(temp+go<=n&&s[temp+go]=='0') {
        temp+=go;
        ans[count]=go;
        count++;
        break;
      }
      else {
        go--;
      }
      if(go<1) {
        flag=true;
        break;
      } 
    }
    if(flag) {
      break;
    }
  }
  if(temp!=n) {
    cout << -1 << endl;
  }
  else {
    for(ll i=count-1;i>-1;i--) {
      if(i!=count-1) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
  }
}