#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
int main() {
  int a; cin >> a;
  int ans =0;
  ans += a + a*a +a*a*a;
  
  cout << ans << endl;
}
