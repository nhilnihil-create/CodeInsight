#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(n); ++i)
#define REP(i, d, n) for(long long i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {

ll a,b; cin>>a>>b;  
  int ans=-1;

  rep(i,10000){
   if( i*0.08>=a && i*0.08<a+1 && i*0.1>=b && i*0.1<b+1 )
   { ans=i; break; }  
  }
  
  cout<<ans<<endl;
  
}
