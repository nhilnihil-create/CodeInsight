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
long long dp[200010];
  
int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  map<ll,ll> mp;
  map<ll,ll> mp2;
  REP(i, N){
    cin >> A[i];
    B.at(i)=A[i]+i;
    mp[B.at(i)]++;
    C.at(i)=-A[i]+i;
    mp2[C.at(i)]++;
  }

  ll cnt = 0;
  for(auto x:mp){
    cnt+=mp2[x.first]*x.second;
  }


  cout << cnt << endl;
}