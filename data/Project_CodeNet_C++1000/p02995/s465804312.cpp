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

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a%b); 
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll tmp = lcm(c, d);
    //cout << tmp << endl;
    ll num1 = b - (b / c + b / d - b / tmp);
    ll num2 = (a-1LL) - ((a-1LL) / c + (a-1LL) / d - (a-1LL)/tmp);
    //cout << num1 << " " << num2 << endl;
    cout << num1 - num2 << endl; 
    return 0;
}
