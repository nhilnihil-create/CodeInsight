#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll h;
    cin >> h;
    ll adder = 1;
    ll tot = 0;
    while (h) {
        h /= 2;
        tot += adder;
        adder *= 2;
    }
    cout << tot << '\n';
}