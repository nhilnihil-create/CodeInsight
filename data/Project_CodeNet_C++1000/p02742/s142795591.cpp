#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000007
#define endl "\n" 
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    ll h, w; cin >> h >> w;
    ll hw = h*w;
    ll ans = 0;
    if(hw % 2 == 0) ans = hw / 2;
    else ans = (hw+1) / 2;

    if(h == 1 || w == 1) ans = 1;

    cout << ans << endl;

    return 0;
}
