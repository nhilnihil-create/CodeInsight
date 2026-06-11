#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

void chmin(int &a, int b){
  if(a > b)
    a = b;
}
void chmax(int &a, int b){
  if(a < b)
    a = b;
}

void llchmin(ll &a, ll b){
  if(a > b)
    a = b;
}
void llchmax(ll &a, ll b){
  if(a < b)
    a = b;
}

ll modPow(ll a, ll n, ll p){
  if(n == 0)
    return 0;
  if(n == 1)
    return a % p;
  if(n % 2 == 1)
    return ((a * modPow(a, n-1, p))%p);
  ll t = modPow(a, n/2, p)%p;
  return t*t%p;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  int p = 1000000007;
  
  ll a_ue = 1, a_sita = 1;
  rep(i, 0, a){
    a_ue = a_ue*(n-i)%p;
    a_sita = a_sita*(i+1)%p;
  }
  
  ll a_sita_ = modPow(a_sita, p-2, p)%p;
  
  ll nCa = a_ue*a_sita_%p;
  
  ll b_ue = 1, b_sita = 1;
  rep(i, 0, b){
    b_ue = b_ue*(n-i)%p;
    b_sita = b_sita*(i+1)%p;
  }
  
  ll b_sita_ = modPow(b_sita, p-2, p)%p;
  
  ll nCb = b_ue*b_sita_%p;
  
  ll n_2 = modPow(2, n, p)%p;
  n_2 = (n_2-1)%p;
  
  ll ans = (n_2-(nCa+nCb)%p)%p;
  if(ans < 0)
    ans += p;
  
  cout << ans << endl;
  
  return 0;
  
}