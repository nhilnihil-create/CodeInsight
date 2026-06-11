#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() 
{
  ll n; cin >> n;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  string ans = "Yes";
  h[0] -= 1;
  rep(i, n-1){
    if (h[i] < h[i+1]) h[i+1] -= 1;
    if (h[i] > h[i+1]){
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
