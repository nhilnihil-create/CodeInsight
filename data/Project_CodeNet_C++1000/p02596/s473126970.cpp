#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  
  ll k;
  cin >> k;
  ll amari = 7%k;
  ll ans = 1;
  while(amari){
    amari *= 10;
    amari += 7;
    amari %= k;
    ans++;
    if(ans>k){
      cout << -1 << endl;
      return 0;      
    }
  }
  cout << ans << endl;
  return 0;
    

}
