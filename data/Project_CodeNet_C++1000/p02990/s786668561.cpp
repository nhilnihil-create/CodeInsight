#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, K;
vector<ll> fac{1};
vector<ll> ifac{1};
vector<ll> inv{1};

ll F(ll N, ll a, ll p){
 
  if(a == 0)return 1;
 
  if(a%2 == 0 && a != 0)return (F(N, a/2, p)*F(N, a/2, p))%p;
 
  if(a%2 == 1)return N*F(N, a - 1, p)%p;
 
}

void C(){

  ll f = 1;

rep(i, 1, N + 1){

  f *= i;f %= PP;

  fac.push_back(f);

}

rep(i, 1, N + 1){

  inv.push_back(F(i, PP - 2, PP));

}

f = 1;

rep(i, 1, N + 1){

  f *= inv[i];f %= PP;
  ifac.push_back(f);

}
}

ll Com(ll n, ll k, ll p){
  
  if(n - k < 0)return 0;

  else return (((fac[n]*ifac[k])%p)*ifac[n - k])%p;

}

int main(){
cin >> N >> K;
  
C();

rep(i, 1, K + 1){

  cout << Com(N - K + 1, i, PP)*Com(K - 1, i - 1, PP)%PP << endl;
  
}

}


