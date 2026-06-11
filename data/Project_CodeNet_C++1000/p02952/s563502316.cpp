#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n;
  cin >> n;
  int ans;
  if(n/10==0) ans=n;
  else if(n/100==0) ans=9;
  else if(n/1000==0) ans=n-90;
  else if(n/10000==0) ans=909;
  else if(n/100000==0) ans=n-90-9000;
  else ans=90909;
  cout << ans << endl;
}
