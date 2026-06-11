#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll t[2],a[2],b[2];
  rep(i,2)cin >> t[i];
  rep(i,2)cin >> a[i];
  rep(i,2)cin >> b[i];
  if(a[0]*t[0]+a[1]*t[1] == b[0]*t[0]+b[1]*t[1]){
    cout << "infinity" << endl;
    return 0;
  }
  if(a[0]*t[0]+a[1]*t[1] < b[0]*t[0]+b[1]*t[1])rep(i,2)swap(a[i],b[i]);
  if(a[0] <= b[0] && a[1] >= b[1]){
    ll one = abs(t[0]*(-b[0]+a[0])+t[1]*(a[1]-b[1]));
    __int128_t left = -1,right = 1e18;
    while(right-left > 1){
      __int128_t mid = (right+left)/2;
      if(one*mid < t[0]*(b[0]-a[0]))left = mid;
      else right = mid;
    }
    ll l = left,r = right;
    if(one*r == t[0]*(b[0]-a[0]))cout << r*2 << endl;
    else cout << l*2+1 << endl;
  }else{
    cout << 0 << endl;
  }





  


  return 0;
}
