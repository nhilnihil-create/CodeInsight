#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};

ll mypow(ll n,ll r){
  ll res = 1;
  while(r){
    if(r & 1)res = res*n%MOD;
    n = n*n%MOD;
    r >>= 1;
  }
  return res;
}

ll oh[2020],reoh[2020];

ll comb(ll n,ll r){
  if(n < r)return 0;
  ll res = oh[n]*reoh[r]%MOD;
  res = res*reoh[n-r]%MOD;
  return res;
}

int main(){

  oh[0] = reoh[0] = 1;
  for(int i = 1;i <= 2010;i++)oh[i] = (oh[i-1]*i)%MOD,reoh[i] = mypow(oh[i],MOD-2);
  
  int n,k;
  cin >> n >> k;
  for(int i = 1;i <= k;i++){
    ll nn = i-1;
    ll res;
    n-k-nn >= 0 ? res = comb(k-1,nn)*comb(n-k-nn+nn+2-1,nn+1)%MOD : res = 0;
    cout << res << endl;
  }




  return 0;
}