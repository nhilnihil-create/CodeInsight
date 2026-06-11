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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, k;
    cin >> n >> k;
    ll s;
    cin >> s;
    rep(i, k) {
        if ( i >= 1 ) cout << " ";
        cout << s;
    }
    rep(i, n - k) {
        cout << " ";
        if ( s == 1e9 ) cout << 1;
        else            cout << s + 1;
    }
    cout << endl;

    return 0;
}
