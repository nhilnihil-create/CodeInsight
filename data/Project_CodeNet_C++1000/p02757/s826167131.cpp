#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  if(p==2||p==5){
    ll ans = 0;
    rep(i,n){
      if((s[i]-'0')%p==0)ans += (n-i);
    }
    cout << ans << endl;
    return 0;
  }
  map<int,int> mp;
  int remain = 0;
  mp[remain]++;
  int mod = 1;
  rep(i,n){
    remain += (s[i]-'0')*mod;
    remain %= p;
    mp[remain]++;
    mod *= 10;
    mod %= p;
  }
  ll ans = 0;
  for(auto p:mp){
    //cout << p.first << " " << p.second << endl;
    ans += (ll)p.second*(p.second-1)/2;
  }
  cout << ans << endl;
}