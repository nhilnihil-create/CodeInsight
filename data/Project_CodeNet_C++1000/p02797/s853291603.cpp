#include <iostream>
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
    int n, k;
    ll s;
    cin >> n >> k >> s;
    ll ans_num;
    ll rep_num;
    if ( s == 1e9 ) {
        rep_num = 1LL;
    }
    else {
        rep_num = s + 1LL;
    }
    int cnt = 0;
    rep(i, n) {
        if ( i != 0 ) cout << " ";
        if ( cnt == k ) cout << rep_num;
        else {
            cout << s;
            ++cnt;
        }
    }
    cout << endl;
    return 0;
}
