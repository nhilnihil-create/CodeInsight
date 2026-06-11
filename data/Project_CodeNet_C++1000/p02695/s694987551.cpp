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

ll fac[MAX], finv[MAX], inv[MAX];

void nCrprep() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll nCr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

ll nCrcheep(ll n,ll r){
  if(r == 0) return 1;
  else if(r == 1) return n;
  else return nCrcheep(n-1,r-1)*n/r;
}

vector<pair<ll,ll>> prime_factorize(ll n){
  vector<pair<ll,ll>> res;
  
  for(ll i=2; i*i <= n; i++){
    if(n % i != 0) continue;
    
    ll ex = 0;
    while(n % i == 0){
      ex++;
      n /= i;
    }
    
    res.push_back({i,ex});
  }
  
  if(n != 1) res.push_back({n,1});
  
  return res;
  
}




int main(){
  ll n,m,q; cin >> n >> m >> q;
  vvl table(q,vl(4));
  
  queue<vl> qu;
  
  rep(i,q){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    table[i][0] = a;
    table[i][1] = b;
    table[i][2] = c;
    table[i][3] = d;
  }
  
  for(ll i=1; i <= m; i++){
    vector<ll> array = {i};
    qu.push(array);
  }
  
  bool flag = true;
  while(flag){
    auto vec = qu.front();
    if(vec.size() == n){
      flag = false;
      break;
    }
    
    qu.pop();
    
    ll a = vec[vec.size()-1];
    
    for(ll i=a; i <= m; i++){
      auto vecd = vec;
      vecd.push_back(i);
      qu.push(vecd);
    }
  }
  
  ll ans = 0;
  while(!qu.empty()){
    auto vec = qu.front(); ll sum = 0;
    qu.pop();
    
    rep(i,q){
      if(vec[table[i][1]-1] - vec[table[i][0]-1] == table[i][2]){
        sum += table[i][3];
      }
    }
    
    ans = max(ans,sum);
  }
  
  cout << ans << endl;
  
  
}