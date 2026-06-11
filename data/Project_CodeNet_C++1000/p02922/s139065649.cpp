#include <bits/stdc++.h>
using namespace std;

int a, b;
int nr, s;

int main() {
    cin >> a >> b;
    s = a;
    nr = 1;
    if(b == 1) {
        cout << 0;
        return 0;
    }
    while(s < b) {
        nr++;
        s = s + a - 1;
    }
    cout << nr;
    return 0;
}