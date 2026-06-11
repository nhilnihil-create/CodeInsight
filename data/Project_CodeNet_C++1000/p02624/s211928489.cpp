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

*/
vector<int> prime(0, 0);
vector<int> cnt(10001001, 2);

void eratos(int n){
  for(int i=2; i<=n; i++){
    ll j = 2;
    while (i*j <= n){
      cnt[i*j]++;
      j++;
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll N, ans = 0; cin >> N;
  eratos(10001000);//nまでの素数を抽出
  cnt[1] = 1;
  for(ll i=1; i<=N; i++)
    ans += i * cnt[i];
//  rep(i, 100)
//    cout<<"i:"<<i+1<<" cnt:"<<cnt[i+1]<<endl;
  cout << ans << endl;
}
