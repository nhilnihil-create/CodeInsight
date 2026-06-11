#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
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
    int n;
    cin >> n;
    for (int i = 1; i < 50000; i++) {
        if ((int)floor((double)i * 1.08) == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}