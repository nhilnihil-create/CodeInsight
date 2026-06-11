#include<bits/stdc++.h>
using namespace std;


int main() {
    float a, b;
    cin >> a >> b;
    if(12.5 * a >= 10 * b + 10 || 10 * b >= 12.5 * a + 12.5) {
        cout << -1 << "\n";
    }
    else if(10 * b >= 12.5 * a) {
        cout << 10 * b << "\n";
    }
    else {
        if(12.5 * a == (int)(12.5 * a)) {
            cout << 12.5 * a << "\n";
        }
        else {
            cout << (int)(12.5 * a + 1) << "\n";
        }
    }
}