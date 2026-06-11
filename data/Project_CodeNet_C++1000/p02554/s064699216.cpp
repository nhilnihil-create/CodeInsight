#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pi;
#define f first
#define s second
#define pb(x) push_back(x)

ll mod = 1e9 + 7;

ll p(ll num, ll power){
  ll ans = 1;
  for(int i=1;i<=power;++i){
    ans *= num;
    ans %= mod;
  }
  return ans%mod;
}

int main() {
  ll n;cin>>n;
  cout<<(p(10,n)%mod - 2*p(9,n)%mod + p(8,n)%mod + mod)%mod;

}