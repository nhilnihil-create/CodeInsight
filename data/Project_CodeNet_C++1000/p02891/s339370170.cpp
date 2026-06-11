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
  ans += num/2;
  if(count == 0){
    cout << num*k/2 << endl;
  }
  else if(s[0] != s[s.size()-1]){
    cout << ans*k << endl;
  }
  else{
    //cout << first << num << endl;
    ll dis = (k-1)*((first+num)/2 - first/2 - num/2);
    cout << ans*k + dis << endl;
  }
}
