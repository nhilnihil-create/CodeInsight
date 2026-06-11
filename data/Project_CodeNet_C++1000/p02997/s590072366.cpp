#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,k;
  cin >> n >> k;
  if(k > (n-1)*(n-2)/2){
    cout << -1 << endl;
    return 0;
  }
  ll m = n-1;
  m += (n-1)*(n-2)/2-k;
  cout << m << endl;
  m -= (n-1);
  rep(i,n-1)cout << 1 << " " << i+2 << endl;
  for(int i = 2;i <= n;i++){
    for(int j = i+1;j <= n;j++){
      if(m == 0)break;
      cout << i << " " << j << endl;
      m--;
    }
  }





  


  return 0;
}