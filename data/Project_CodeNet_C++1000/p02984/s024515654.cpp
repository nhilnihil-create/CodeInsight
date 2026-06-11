#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


// max_rain = 2*A = 2*10^9;
// ans[]=

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> r(n);

  r[n-1] = a[n-1];
  rep(i,n-1){
    r[n-1] += a[i]*pow(-1,i+1);
  }

  r[0] = 2*a[n-1]-r[n-1];

  for(int i = 1; i<n-1; i++){
    r[i] = 2*a[i-1]-r[i-1];
  }

  rep(i,n) cout << r[i] << " ";
  cout << endl;
  
  
}
