#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}

int main(){
  fastIO();
  ll a,b,n;
  cin>>a>>b>>n;
  ll c = min(n,b-1);
  cout<<((a*c)/b) - (a*(c/b));
  return 0;
}