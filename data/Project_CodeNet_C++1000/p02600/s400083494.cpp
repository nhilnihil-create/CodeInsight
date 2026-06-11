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
    int n, a;
    cin >> n;
    if (n >= 400 && n < 600) a = 8;
    else if (n >= 600 && n < 800) a = 7;
    else if (n >= 800 && n < 1000) a = 6;
    else if (n >= 1000 && n < 1200) a = 5;
    else if (n >= 1200 && n < 1400) a = 4;
    else if (n >= 1400 && n < 1600) a = 3;
    else if (n >= 1600 && n < 1800) a = 2;
    else a = 1;
    cout << a << endl;
}