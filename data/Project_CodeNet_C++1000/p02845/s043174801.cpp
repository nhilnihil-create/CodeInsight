#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;

int main(){
  ll n,a,ans=1;
  vector<ll>x(3,-1);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    ll count=0; 
    for(int j=0; j<3; j++){ 
      if(x[j]==a-1) count++;
    }
    if(x[0]==a-1)x[0]++;
    else if(x[0]!=a-1 && x[1]==a-1)x[1]++;
    else x[2]++;
    ans*=count;
    ans%=mod;
  }
  
  cout << ans << endl;
  
}