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

void eratos(int n){
  vector<bool> N(n+10,true);
  N[0] = false;
  N[1] = false;
  for(int i=2; i<=n; i++){
    if (N[i])
      prime.push_back(i);
    int j=2;
    while (i*j <= n)
      N[i*j++] = false;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  eratos(1001000);//nまでの素数を抽出
  
  ll N; cin >> N;
  ll cnt = 0;
  ll end = prime.size();
  for(ll i=0; i<end; i++){
    ll tmp=0;
    while (N % prime[i] == 0){
      N /= prime[i];
      tmp++;
    }
    ll j = 1;
    while (tmp - j >= 0){
      tmp -= j;
      j++;
      cnt++;
    }
    if (N < prime[i])
      break;
    if (i == end -1)
      cnt++;
  }
  cout << cnt << endl;
}
