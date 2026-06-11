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

int main(){
  int n; cin >>n;
  vector<int>a(n+1); vector<int>b(n); ll sum=0;
  for(int i=0; i<=n; i++) cin >>a[i];
  for(int i=0; i<n; i++) cin >>b[i];
  for(int i=0; i<n; i++){
    if(b[i]>=a[i]){
      sum+=a[i]; b[i]-=a[i];
      if(b[i]>=a[i+1]){sum+=a[i+1]; a[i+1]=0;}
      else{sum+=b[i]; a[i+1]-=b[i];}
    }
    else sum+=b[i];
  }
  cout <<sum;
return 0;}