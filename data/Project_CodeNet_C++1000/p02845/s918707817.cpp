#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long int;
using namespace std;
ll mod=1e9+7;


int main() {
  ll ans=1;
  int n;
  cin >> n;
  ll a[n+1]={};
  a[0]=3;

  rep(i,n){
      int q;
      cin >> q;
      if(a[q]>0){
          ans=ans*a[q]%mod;
          a[q]--;
          a[q+1]++;
        }else{
          cout << 0 << endl;
          return 0;
        }
    }
    cout << ans << endl;
}