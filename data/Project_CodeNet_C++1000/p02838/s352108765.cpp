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



int main(){
  ll n; cin >> n; vl bit1(62); vl bit0(62);
  
  rep(i,n){
    ll x; cin >> x;
    
    ll b = 1;
      for(ll j=0; j < 62; j++){
        if(x % 2 == 0){
          bit0[j]++;
        }
        else bit1[j]++;
       
        
        x /= 2;
      }
    
  }
  
  ll MOD = 1000000007;
  ll ans = 0;
	rep(i,62){
		ll num2 = bit1[i]*(n-bit1[i])%MOD;
		for(ll j=0;j<i;j++){
			num2 *= 2;
			num2 %= MOD;
		}
		ans += num2;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
  

  /*ll sum = 0;
  
  ll index = 1;
  
  rep(i,62){
      
    sum += mod(bit1[i]*bit0[i])*mod(index); 
    sum = mod(sum);
    
    index *= 2; index = mod(index);
  }
  
  cout << sum << endl;*/
  
  
}
    
