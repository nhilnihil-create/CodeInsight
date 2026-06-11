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
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (abs(a-b)%2==0) {
        cout << abs(a-b)/2LL << endl;
        return 0;
    }
    ll tmp1 = min(abs(a-1LL), abs(b-n));
    ll tmp2 = min(abs(b-1LL), abs(b-n));
    //cout << (abs(a-b)-1LL)/2LL << " " << tmp1 << " " << tmp2 << endl;
    cout << (abs(a-b)-1LL)/2LL + min(tmp1, tmp2) + 1LL << endl;
    return 0;
}
