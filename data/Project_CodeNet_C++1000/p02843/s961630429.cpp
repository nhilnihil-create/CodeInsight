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
    int x;
    cin >> x;
    int a = x % 100;
    int b = x / 100;
    int hund = 0;
    while(a >= 5) {
        a -= 5;
        hund++;
    }
    while(a >= 4) {
        a -= 4;
        hund++;
    }
    while(a >= 3) {
        a -= 3;
        hund++;
    }
    while(a >= 2) {
        a -= 1;
        hund++;
    }
    while(a >= 1) {
        a -= 1;
        hund++;
    }
    if (hund > b) {
        cout << 0 << endl;
    }
    else cout << 1 << endl;
}