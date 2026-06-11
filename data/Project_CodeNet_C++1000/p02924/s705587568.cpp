#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  ll ans = (n+1)*(n-2)/2 + 1;
  cout << ans << endl;  
}
