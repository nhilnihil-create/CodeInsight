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
vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}
int main()
{
  int N;
  cin >> N;
  vector<int> A(N+1);
  FOR(i,1,N+1) cin >> A[i];
  
  vector<int> B;
  for(int i=N;i>0;i--){
    vector<ll> vec=divisor(i);
    if(A[i]%2==1){
      for(auto x:vec){
        A[x]++;
      }
      B.push_back(i);
    }
  }
  cout << B.size() << endl;
  if(B.size()>0){
    REP(i,B.size()){
      cout << B.at(i);
      if(i!=B.size()){
        cout << " ";
      }
    }
    cout << endl;
  }
}