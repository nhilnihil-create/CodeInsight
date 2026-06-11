#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll n, ll k){
  if(k==0) return n;
  else return GCD(k, n%k);
}
 
int main(){
  ll a, b;
  cin >> a >> b;
  vector<bool> isPrime(1000007, true);
  isPrime[0] = false;
  isPrime[1] = false;
  ll c = GCD(max(a,b), min(a,b));
  int ans = 0;
  for(ll i=2; i*i<=c; i++){
    if(c%i==0){
      while(c%i==0){
        c/=i;
      }
      ans++;
    }
  }
  if(c==1) ans += 1;
  else ans += 2;
  cout << ans << endl;
  return 0;
}
