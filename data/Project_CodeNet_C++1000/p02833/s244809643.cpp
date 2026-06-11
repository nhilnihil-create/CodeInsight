#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll n;
  cin >> n;
  if(n%2==1){
    cout << 0 << "\n";
    return 0;
  }
  ll ans=0;
  while(n>=10){
    ans+=n/10;
    n/=5;
  }
  cout << ans << "\n";  
  return 0;
}