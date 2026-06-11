#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cout<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;
struct Edge{ll from, to, cost;};

ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N;
  cin >> N;
  llvec A(N);
  llvec S1(N), S2(N);
  cin >> A[0];
  rep(i, N-1){
    cin >> A[i+1];
  }
  sort(ALL(A));
  S1[0] = A[0];
  S2[0] = -A[0];
  for(int i=1; i<N;i++){
    S1[i] = S1[i-1]+A[i];
    S2[i] = S2[i-1]-A[i];
  }
  ll ans = -1e16;
  ll ansind=0;
  for(int i=1;i<N;i++){
    ll tmp = S2[i-1]+(S1[N-1]-S1[i-1]);
    if(tmp >= ans){
      ans = tmp;
      ansind=i;
    }
  }
  cout << ans << endl;
  ll a = A[0];
  rep(i, N-ansind-1){
    cout << a << " " << A[ansind+i] << endl;
    a = a - A[ansind+i];
  }
  
  cout << A[N-1] << " "<< a << endl;
  a = A[N-1] - a;
  for(int i=1;i<ansind;i++){
    cout << a << " " << A[i] << endl;
    a = a - A[i];
  }

 
  //cout << ans << " " << ansind;
    
  return 0;
}
