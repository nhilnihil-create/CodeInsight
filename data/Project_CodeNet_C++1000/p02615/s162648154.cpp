#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
  ll n,k,ans=0;
  cin >> n;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  
  sort(a,a+n);
  
  for(int i=1; i<=n-1; i++){
    k = n-(i/2);
    ans += a[k-1];
  }
  
  cout << ans << endl;
  
  return 0;
}
