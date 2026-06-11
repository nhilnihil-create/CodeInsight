#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<vector<int>> v;
  rep(i,N-1){
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    v.push_back({a,b});
  }

  ll ret = 0;
  for(int i=N; i>0; i--){
    ret += (ll)i * (i+1) / 2;
  }

  rep(i,v.size()){
    ll a = v[i][0];
    ll b = v[i][1];

    ll tmp = a * (N+1-b);
    ret -= tmp;
  }

  cout << ret << endl;
  
  return 0;
}

