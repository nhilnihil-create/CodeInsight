#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265358979
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N,A,B;
  cin>>N>>A>>B;
  unsigned long long ans=0;
  if((B-A)%2ll==0){
    ans=abs((B-A)/2ll);
  }
  else{
  	unsigned long long p=N-(A+B-1ll)/2ll,q=(A+B-1ll)/2ll;
  	ans=min(p,q);
  }
  cout<<ans;
  
}