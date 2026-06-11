#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[200000];
  
int main()
{
  string S;
  cin >> S;
  int N = S.size();
  map<int,int> mp;
  mp[S.at(N-1)-'0']++;
  int cnt = 1;
  int pre = S.at(N-1)-'0';
  FOR(i,1,N){
    mp[(((cnt*10)%2019)*(S.at(N-1-i)-'0')+pre)%2019]++;
    pre=(((cnt*10)%2019)*(S.at(N-1-i)-'0')+pre)%2019;
    cnt=(cnt*10)%2019;
  }

  mp[0]++;
  ll ans = 0;
  for(auto x:mp){
    ans+=x.second*(x.second-1)/2;
  }

  cout << ans << endl;
}