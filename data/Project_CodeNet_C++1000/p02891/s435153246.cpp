#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;
ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
  string s;
  ll k;
  cin >> s >> k;

  set<char> st;
  rep(i, s.size()){
    st.insert(s[i]);
  }

  if(st.size() == 1){
    cout << (ll)s.size() * k / 2 << endl;
    return 0;
  }

  ll ans = 0;
  if(s[0] != s[s.size() - 1]){
    ll same = 1;
    for(int i = 1; i < s.size(); ++i){
      if(s[i - 1] == s[i]){
        same++;
      }
      else{
        ans += same / 2;
        same = 1;
      }
    }
    ans += same / 2;
    cout << ans * k << endl;
  }
  else{
    ll lsame = 1;
    for(int i = 1; i < s.size(); ++i){
      if(s[0] == s[i]){
        lsame++;
      }
      else{
        break;
      }
    }
    ll rsame = 1;
    for(int i = s.size() - 2; i >= 0; --i){
      if(s[0] == s[i]){
        rsame++;
      }
      else{
        break;
      }
    }
    ll msame = 1;
    ll msamet = 0;
    for(int i = lsame + 1; i < s.size() - rsame; ++i){
      if(s[i - 1] == s[i]){
        msame++;
      }
      else{
        msamet += msame / 2;
        msame = 1;
      }
    }
    msamet += msame / 2;
    ans = msamet * k + lsame / 2 + rsame / 2 + (lsame + rsame) / 2 * (k - 1);
    cout << ans << endl;
  }

  return 0;
}