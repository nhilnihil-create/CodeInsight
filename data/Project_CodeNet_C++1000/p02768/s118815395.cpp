#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(int i=0;i<n;i++)
#define vec vector
typedef int64_t intl;
#define fi first
#define se second
#define pushb push_back
#define popb pop_back
#define SortA(c) sort(c.begin(), c.end())
#define SortD(c) sort(c.rbegin(), c.rend())
const intl mod = 1000000007;

intl modpow(intl a, intl n, intl p){
  intl res = 1;
  while (n > 0){
    if (n&1){res = (res * a) % p;}
	a = (a * a) % p;
    n >>= 1;
  }
  return res;
}

intl modinv(intl a, intl p){
  if (a == 0){
    cout << "/0 at modinv"<<endl;
    exit(0);
  }
  if ( __gcd(a,p) !=1 ){
    cout << "inv_a does not exist."<<endl;
    exit(0);
  }
  if (a < 0){
    cout << "/- at modinv" <<endl;
    exit(0);
  }
  if (a==1){return 1;}
  if (a > p){return modinv(a%p, p);}

  return p - ( modinv(p%a,p) * (p/a) ) % p;
}

intl modcomb(intl n, intl k, intl p){
  if (k > n || k < 0 || n < 0){
    cout << "error at modcomb"<<endl;
    exit(0);
  }
  if (2*k > n){ k = n-k;}
  if (k ==0){return 1;}
  intl c=1;
  for (intl i = 0; i < k; i++){
    c =( c * ( (n-i) % p ) % p ) * modinv(i+1,p) % p;
  }
  return c;
}

int main(){
  intl n,a,b;
  cin >> n >> a >> b;
  if (n==2){
    cout << 0;
    return 0;
  }
  
  intl ans;
  ans = modpow(2, n, mod);
  ans -= modcomb(n, a, mod);
  ans -= modcomb(n, b, mod);
  ans -= 1;
  while (ans < 0){
    ans += mod;
  }
  cout << ans;
}