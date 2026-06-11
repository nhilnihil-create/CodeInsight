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
    int x;
    cin >> x;
    for ( int i = 1; i * 100 <= x; ++i ) {
        int y = x - i * 100;
        if ( y <= 5 * i ) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
