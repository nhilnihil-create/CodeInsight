#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;
static const long long MAX = 1000000000;

ll S, _x1, _y1, _x2 = 1, _y2 = MAX, _x3 = 0, _y3 = 0;

/*
S = x1y2 - x2y1
y2 = 1e9, x2 = 1

x1 * 1e9 - y1 = S

*/

int main(void) {
    cin >> S;
    ll q = S/MAX, r = S%MAX;
    if (r!=0){
        _x1 = q+1;
        _y1 = MAX-r;
    } else {
        _x1 = q;
        _y1 = r;
    }

    //cout << _x1*_y2 - _x2*_y1 << endl;
    printf("%lld %lld %lld %lld %lld %lld\n", _x1, _y1, _x2, _y2, _x3, _y3);

	return 0;
}
