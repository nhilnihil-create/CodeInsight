#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i) = 0; (i) <(n); (i)++) 
#define so(v) sort(v.begin(),v.end())
using ll = long long;
using vi=vector<int>;
using vii=vector<vi>;
const int MAX = 510000;
const int MOD = 1000000007;
ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
 string s;ll k;cin>>s>>k;
  ll n=s.size();
  char x=s.at(0);
  bool b=true;
  rep(i,n){
    if(x!=s.at(i))b=false;
  }
  if(b){
    cout<<(n*k)/2<<endl;
    return 0;
  }
  
  int j=1;
  int count=0;
  for(int i=1;i<n;i++){
    if(s.at(i)==s.at(i-1)){
     j++;
    }
    else {
      count+=j/2;
      j=1;
    }
  }
  count+=j/2;
  if(s.at(0)!=s.at(n-1)){
    cout<<count*k<<endl;
  }
  else{
    ll a=1;
    for(int i=1;i<n;i++){
      if(s.at(i)==s.at(i-1)){
        a++;
      }
      else break;    
  }
  ll b=1;
  for(int i=n-2;i>=0;i--){
      if(s.at(i)==s.at(i+1)){
        b++;
      }
      else break;    
  }
  cout<<(count)*k+((a+b)/2-(a/2)-(b/2))*(k-1)<<endl;
  
}

}
 