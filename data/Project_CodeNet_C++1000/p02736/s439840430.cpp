#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *x,ll *y) {
  ll tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
  return modpow(a, mod - 2, mod);
}

ll calc(ll k){
  ll sum = 0;
  while(k % 2 == 0){
    sum++;
    k /= 2;
  }
  return sum;
}


int main(){
  ll n;
  cin >> n;
  vector<ll> com(n+1,0);
  vector<ll> div(n+1,true);
  vector<ll> vec(n);
  string str;
  cin >> str;
  ll sum = 0;
  ll ans = 0;
  ll cou = 0;

  ll t1 = 2;
  while(t1 <= n){
    t2 = t1;
    while(t2 <= n){
      com[t2]++;
      t2 += t1;
    }
    t1 *= 2;
  }
  t1 = 0;
  rep(i,n){
    t1 += com[i];
    com[i] = t1;
    //cout << com[i] << " ";
  }

  rep(i,n){
    t1 = com[n-1] - com[n-1-i] - com[i];
    //cout << t1 << " ";
    if(t1 > 0){
      div[i] = false;
    }
  }
  bool can = true;
  rep(i,n){
    vec[i] = str[i] - 49;
    if(vec[i] % 2 != 0){
      can = false;
    }else if(vec[i] == 2){
      cou++;
    }
    sum += div[i] * vec[i];
    //cout << com[i] << " " << vec[i] << endl;
  }
  if(sum % 2 == 0){
    if(can){
      rep(i,n){
        vec[i] /= 2;
      }
      sum = 0;
      rep(i,n){
        sum += div[i] * vec[i];
        //cout << com[i] << " " << vec[i] << endl;
      }
      if(sum % 2 != 0){
        ans = 2;
      }else{
        ans = 0;
      }
    }else{
      ans = 0;
    }
  }else{
    ans = 1;
  }
  cout << ans << endl;
}
