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

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll n; cin >> n;
  string ans = "";
  
  while(n != 0){
    
    ll per = n % 26;
    
    if(per != 0) ans += small[per-1];
    else ans += "z";
    
    if(n % 26 != 0) n /= 26;
    else{ n /= 26; n--; }
  }
  
  reverse(all(ans));
  
  cout << ans << endl;
  
  
}