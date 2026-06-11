#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
    if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
    }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



int main() {
  string s;
  ll k;
  cin >> s >> k;
  int n=s.size();
  
  ll ans=0;
  ll ren=1;
  
  if(s[0]!=s[n-1]) {
    repo(i,n) {
      if(s[i]!=s[i-1]) ans+=ren/2, ren=1;
      else ren++;
    }
  ans+=ren/2;
  ans*=k;
  }
  
  else{
    int st=0;
    int go=n-1;
    ll aida;
    rep(i,n){
      if(s[i]!=s[0]) {
        st=i;
        break;
      }
    }
    for(int i=n-1;i>=0;i--){
      if(s[i]!=s[0]) {
        go=i; 
        break;
      }
    }
    if(st==0 && go==n-1) {
      cout << n*k/2 << endl;
      return 0;    
    }
    aida=(st+n-1-go)/2;
        
    for(int i=st;i<=go;i++){
      if(s[i]!=s[i-1]) ans+=ren/2, ren=1;
      else ren++;
    }
    ans+=ren/2;
        
    ans=ans*k+aida*(k-1)+st/2+(n-1-go)/2;
  }
    
  cout << ans << endl;
  
}
