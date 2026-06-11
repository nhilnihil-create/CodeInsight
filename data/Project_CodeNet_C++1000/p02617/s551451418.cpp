#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
頂点-辺

1 2 3 4 5

2-3とか
11
12 22
13 23 33  2
14 24 34 44  2
15 25 35 45 55  2 = 3以降の、1と2のカウントだけ。
2-3 = 2 * (5-3+1) = 
辺数
L-R = L * (N-R+1)
頂点 2
11
12 22 2
13 23 33 2
1＝N
2 = (N-2+1)*2
3 = (N-3+1)*3

N=5
1*5 + 4*2 + 3*3 + 2*4 + 1*5

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N; cin >> N;
  ll side=0, edge=0;
  for(ll i=1; i<=N; i++)
    edge += i * (N-i+1);
  rep(i, N-1){
    ll u, v; cin >> u >> v;
    if (v < u)
      swap(u, v);
//cout <<u<<" "<<v<<endl;    
    side += u * (N - v + 1);
  }
  ll ans = edge - side;
  cout << ans << endl;
}
