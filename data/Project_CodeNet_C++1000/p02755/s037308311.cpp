#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
#include <bitset>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int a, b;
    cin >> a >> b;
    rep(i, 100000) {
        if (floor((double)i * 1.08) == a + i && floor((double)i * 1.1) == b + i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}