#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 2019;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  string s; cin >> s; ll n = s.size();
  
  reverse(all(s));
  
  vl per(2019,0LL);
  
  ll now = 0; ll pow10 = 1;
  per[0]++;
  
  rep(i,n){
    now += (s[i] - '0')*pow10;
    pow10 *= 10;
    pow10 = mod(pow10);
    now = mod(now);
    
    per[now]++;
  }
  
  ll ans = 0;
  
  rep(i,2019){
    ans += per[i]*(per[i]-1)/2;
  }
  
  cout << ans << endl;
  
  
}