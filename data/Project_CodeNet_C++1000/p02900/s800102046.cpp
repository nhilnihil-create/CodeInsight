#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

vector<ll> prime;

void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
    for(int i=2;i<=l;i++){
        if(n%i==0){
        prime_factorize(i);
	prime_factorize(ll(n/i));
	return;
        }
    }
    prime.push_back(n);
    return;
}

int main(){
  ll A,B;
  cin >> A >> B;
  ll max= GCD(A,B);
  prime_factorize(max);
  ll ans = 0;
  prime.push_back(0);
  for(int i=0;i<prime.size();i++){
    if(prime[i]!=prime[i+1]) ans++;
  }
  ans++;
  cout << ans << endl;
}
