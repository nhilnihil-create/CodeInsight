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
  ll k; cin >> k; ll ans = 0;
  
  queue<ll> q;
  
  rep(i,9) q.push(i+1);
  
  while(k != 0){
    ll now = q.front();
    k--;
    q.pop();
    
    if(k == 0){
      ans = now;
      break;
    }
    
    ll per = now % 10;
    
    if(per != 0){
      q.push(now*10 + per-1);
    }
    q.push(now*10 + per);
    if(per != 9){
      q.push(now*10 + per+1);
    }
  }
  
  cout << ans << endl;
  
  
}