#include <bits/stdc++.h>
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main(){
  int n,p; string s; cin >>n >>p >>s; ll ans=0;
  for(int i=0; i<n; i++) s[i]-='0';
  if(p==2||p==5){
    for(int i=0; i<n; i++) if(s[i]%p==0) ans+=i+1;
    cout <<ans;
  }
  else{
    int x=1,v=0; vector<ll>r(p,0);
    for(int i=1; i<=n; i++){
      v=(v+x*s[n-i])%p;
      r[v]++; x=(x*10)%p;
    }
    for(int i=0; i<p; i++) ans+=r[i]*(r[i]-1)/2;
    cout <<ans+r[0];
  }
return 0;}