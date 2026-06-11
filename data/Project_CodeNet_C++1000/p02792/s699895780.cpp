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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> cnt(10, vector<ll>(10));
    for ( int i = 1; i <= n; ++i ) {
        int w = i;
        while(1) {
            if ( w < 10 ) break;
            w /= 10;
        }
        ++cnt[w][i%10];
    }
    ll ans = 0;
    for ( int i = 1; i < 10; ++i ) {
        for ( int j = 1; j < 10; ++j ) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}
