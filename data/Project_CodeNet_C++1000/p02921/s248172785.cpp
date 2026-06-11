#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s, t;
    cin >> s >> t;
    int ans = 0;
    rep(i, 3) {
        if ( s[i] == t[i] ) ++ans; 
    }
    cout << ans << endl;
    return 0;
}
