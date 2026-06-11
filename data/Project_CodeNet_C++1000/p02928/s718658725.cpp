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

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll nCr(ll n,ll r){
  if(r == 1) return n;
  else if(r == 0) return 1;
  else return nCr(n-1,r-1)*n/r;
}

int main(){
  ll n,k; cin >> n >> k; ll ans1 = 0; ll ans2 = 0; vl num(n);
  vl cntnum(2000); vl sumnum(2000);
  
  rep(i,n){
    ll x; cin >> x; 
    x--;
    num[i] = x;
    cntnum[x]++;
  }
  
  for(ll i=0; i < n; i++){
    for(ll j=i+1; j < n; j++){
      if(num[i] > num[j]) ans1++;
    }
  }
  
  ans1 = mod(ans1);
  
  sumnum[0] = cntnum[0];
  rep(i,1999){
    sumnum[i+1] = sumnum[i] + cntnum[i+1];
  }
  
  for(ll i=0; i < n; i++){
    if(num[i] != 0){
      ans2 += sumnum[num[i]-1];
    }
  }
  
  ans2 = mod(ans2);
  
  cout << mod(mod(k*ans1) + mod(mod(k*(k-1)/2)*ans2)) << endl;
  
}