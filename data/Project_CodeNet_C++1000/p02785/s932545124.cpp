#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll>h(n);
  rep(i,n){
    cin >> h[i];
  }
  sort(h.begin(),h.end());
  ll m=0;
  rep(i,n-k){
    m+=h[i];
  }
  cout << m << endl;
    
 
  return 0;

}