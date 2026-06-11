#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILL(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define INF (1 << 29)
#define MOD 1000000007
//int dx[4] = {1,0,0,-1};
//int dy[4] = {0,1,-1,0};


int main(){

  int n;
  string s;
  cin >> n >> s;
  if(n >= 3200)cout << s;
  else cout << "red";


  return 0;
}
