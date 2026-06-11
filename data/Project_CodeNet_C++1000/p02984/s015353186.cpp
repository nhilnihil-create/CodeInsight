#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;
 
void solve(){
  int n; cin >>n;
  ll a[n],b[n],sum=0;
  for(int i=0; i<n; i++){cin >>a[i]; sum+=a[i];}
  if(n==3) for(int i=1; i<4; i++) cout <<sum-2*a[i%3]<<' ';
  else{
    ll t=0;
    for(int i=1; i<n; i+=2) t+=a[i];
    for(int i=0; i<n; i++){
      b[(2*i)%n]=t;
      t+=a[(2*i)%n]-a[(2*i+1)%n];
    }
    for(int i=0; i<n; i++) cout <<sum-2*b[i]<<' ';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}