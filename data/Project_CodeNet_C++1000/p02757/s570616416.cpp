#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

ll ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

ll factmod(ll a,ll b,ll m) {
  if(a<b)return 0;
  ll s=1;
  while(a>=b){
    s = s*a % m;
    a -= 1;
  }
  return s;
}

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

ll combmod(ll a,ll b,ll m){
  if(b==0)return 1;
  ll c=factmod(a,a-b+1,m);
  ll d=modinv(factmod(b,1,m),m);
  ll e=(c*d)%m;
  return e;
}

void modsum(ll &a,ll b,ll m){
  a+=b;
  a%=m;
}

void modsub(ll &a,ll b,ll m){
  a-=b;
  a+=m;
  a%=m;
}

void modmul(ll &a,ll b,ll m){
  a*=b;
  a%=m;
}

void modquo(ll &a,ll b,ll m){
  a*=modinv(b,m);
  a%=m;
}

int main(){

  ll n,p;
  string s;
  cin >> n >> p >> s;

  ll ans=0;

  if(p==2){
    for(ll i=n-1;i>=0;i--){
      if(ctoi(s[i])&1);
      else ans+=i+1;
    }
  }
  else if(p==5){
    for(ll i=n-1;i>=0;i--){
      if(ctoi(s[i])%5!=0);
      else ans+=i+1;
    }
  }
  else{
    vec a(n+1);
    ll d=1;
    for(ll i=0;i<n;i++){
      ll b=ctoi(s[n-1-i]);
      if(i!=0)d=(d*10)%p;
      a[i+1]=a[i]+d*b%p;
      a[i+1]%=p;
    }

    vec b=a,c=a;
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(ll i=0;i<c.size();i++){
      ll e=upper_bound(b.begin(),b.end(),c[i])-lower_bound(b.begin(),b.end(),c[i]);
      ans+=e*(e-1)/2;
    }
  }
  

  cout << ans << endl;

}