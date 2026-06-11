#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N, K;
  cin >> N >> K;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  vector<ll> R(N+1,0);
  rep(i,N){
    R[i+1] = R[i] + v[i];
  }
  vector<ll> Q(N+1,0);
  Q[0] = 1;
  REP(i,1,N+1){
    Q[i] = (R[i] - ((i-1)%K) + K) % K;

  }

  ll ret = 0;
  map<int,int> m;
  rep(i,N+1){
    if(i>=K) m[Q[i-K]]--;
    ret += m[Q[i]];
    m[Q[i]]++;
  }


  cout << ret << endl;
  
  return 0;
}

