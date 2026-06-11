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
    string s;
    ll k;
    cin >> s >> k;
    string t = s + s + "?";
    s += "?";
    int n = t.length();
    int m = s.length();
    ll num2 = 0;
    ll cnt = 1;
    rep(i, n-1) {
        if ( t[i] == t[i+1] ) ++cnt;
        else {
            num2 += cnt / 2LL;
            cnt = 1;
        }
    }
    cnt = 1;
    ll num1 = 0;
    bool flg = true;
    rep(i, m-1 ) {
        if ( s[i] == s[i+1] ) ++cnt;
        else {
            if ( i != m - 2 ) flg = false;
            num1 += cnt / 2LL;
            cnt = 1;
        }
    }
//    cout << flg << endl;
    if ( flg ) {
        ll len = 1LL * (ll)(s.size()-1) * k;
        cout << len / 2LL << endl;
    }
    else {
//        cout << "moge" << endl;
        cout << num1 + ( k - 1LL ) * ( num2 - num1 ) << endl;
    }
    return 0;
}
