#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll num = 1;
  ll first = 0;
  ll count = 0;
  ll ans = 0;
  rep(i,s.size()-1){
    if(s[i] == s[i + 1]){
      num++;
    }
    else{
      if(count == 0){
        first = num;
      }
      ans += num/2;
      count++;
      num = 1;
    }
  }
  ll a = 1;
  ll b = 1;
  for(int i = 1; i < s.size(); i++) {
    if(s[i] == s[0]){
      a ++;
    }
    else{
      break;
    }
  }
  for(int i = 1; i < s.size(); i++) {
    if(s[s.size() - i - 1] == s[s.size() - 1]){
      b++;
    }
    else{
      break;
    }
  }
  ans += num/2;
  if(count == 0){
    cout << num*k/2 << endl;
  }
  else if(s[0] != s[s.size()-1]){
    cout << ans*k << endl;
  }
  else{
    //cout << first << " " << num << endl;
    cout << ans * k + (k - 1) * ((a + b) / 2 - (a / 2) - (b / 2)) << endl;
  }
}
