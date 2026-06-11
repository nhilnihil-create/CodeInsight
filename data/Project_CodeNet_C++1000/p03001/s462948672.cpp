#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    double ans;
    ll hasMultiAns = 0;
    ans = (double)(W * H) / 2.0;
    if(x * 2 == W && y * 2 == H){
        hasMultiAns = 1;
    }

    cout << std::fixed << std::setprecision(12) << ans << " " << hasMultiAns << endl;

    return 0;
}
