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
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int n = 0;
    while(true) {
        if (b > a) break;
        else {
            b *= 2;
            n++;
        }
    }
    while (true) {
        if (c > b) break;
        else {
            c *= 2;
            n++;
        }
    }
    if (n <= k) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}