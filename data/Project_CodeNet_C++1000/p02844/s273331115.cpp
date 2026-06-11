#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

ll pow_mod(ll a, ll n, ll MOD){
  ll m[60]; m[0]=a; // m[i] : a^(2^i)をMODで割った余り
  rep(i,59) m[i+1] = (m[i]*m[i])%MOD;

  ll retval = 1;
  bitset<60> s(n);
  rep(i,60) if (s.test(i)) (retval *= m[i]) %= MOD;

  return retval; 
}

int main(){
  int N; cin >> N;
  string s; cin >> s;
  int c[N]; rep(i,N) c[i] = s[i]-'0';
 
  int cnt = 0;
  rep(i,10) rep(j,10) rep(k,10){
    int idx_i = find(c,c+N,i) - c;
    int idx_j = find(c+idx_i+1,c+N,j) - c;
    int idx_k = find(c+idx_j+1,c+N,k) - c;
    if (idx_i<N && idx_j<N && idx_k<N) cnt++;
  }
  cout << cnt << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
