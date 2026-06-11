#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 1; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if (a >= k) {
        cout << k << endl;
        return 0;
    }

    int tmp = k - a;
    if (tmp <= b) {
        cout << a << endl;
        return 0;
    }
    tmp -= b;
    if (tmp <= c) {
        cout << a - (k - (a + b)) << endl;
        return 0;
    }
    
}