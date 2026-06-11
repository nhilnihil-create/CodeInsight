#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    bool c = false;
    int p = 10 * b;
    for(int i = 0; i < 10; i++) {
        int pp = p + i;
        pp *= 0.08;
        if(pp == a) {
            p = p + i;
            c = true;
            break;
        }
    }
    if(c) {
        cout << p << endl;
    }
    else {
        cout << -1 << endl;
    }
}