#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int x, y;
  cin >> x >> y;
  int ans = 0;
  int base = 100000;
  ans += max(0, (4 - x) * base);
  ans += max(0, (4 - y) * base);
  if(x == y && x == 1) ans += 4 * base;
  cout << ans << endl; 
}
