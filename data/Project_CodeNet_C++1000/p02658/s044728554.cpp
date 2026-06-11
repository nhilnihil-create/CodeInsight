#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;




int main() {
  int N;
  cin >> N;
 ll ans = 1,a;
 ll inf = 1e18;
 bool f = false;
  rep(i,N) {
    cin >> a;
    if(a == 0) {
      cout << 0 << endl;
      return 0;
    }
    if(ans > inf/a) {
      f = true;
    }

    ans *= a;
  }
  if(f) {
    cout << -1 << endl;
    return 0;
  }
   
  cout << ans << endl;

  return 0;
}








