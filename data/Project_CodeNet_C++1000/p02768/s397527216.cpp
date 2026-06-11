#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

lli mul(lli a,lli b){
  return (a%mod * b%mod)%mod;
}

lli add(lli a,lli b){
  return (a%mod + b%mod)%mod;
}

lli sub(lli a,lli b){
  return (a%mod-b%mod+mod)%mod;
}
 
//############################ENDOFTEMPLATE############################

void solve(){
  lli n;
  cin>>n;
  lli a,b;
  cin>>a>>b;

  vlli fact(200005);

  fact[1] = 1;
  for(lli i = 2;i<=200000;i++){
    fact[i] = (i%mod*fact[i-1]%mod)%mod;
  }

  lli num1 = 1;
  lli val = n;
  for(int i = 0;i<a;i++){
    num1 = (num1%mod*val%mod)%mod;
    val--;
  }

  lli num2 = 1;
  val = n;
  for(int i = 0;i<b;i++){
    num2 = (num2%mod*val%mod)%mod;
    val--;
  }

  lli ans = (binpow(2,n,mod)-1+mod)%mod;
  ans = (ans%mod-(num1%mod*binpow(fact[a],mod-2,mod))%mod+mod)%mod;

  ans = (ans%mod-(num2%mod*binpow(fact[b],mod-2,mod))%mod+mod)%mod;

  cout<<ans;

}

 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}