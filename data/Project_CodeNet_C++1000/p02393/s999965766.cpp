#include<iostream>
using namespace std;
int main() {
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c;
    if (a <= b) {
        d = a;
        e = b;
    } else {
        d = b;
        e = a;
    }

    if (e <= c) {
        f = c;
    } else {
        f = e;
        e = c;
    }

    if (d > e) {
        g = d;
        d = e;
        e = g;
    }
    
    cout << d << " " << e << " " << f << endl;
    
    return 0;
}
