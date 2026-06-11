#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    
    for (;a >= b || b >= c;k--) {
        if (a >= b) {
            b *= 2;
            continue;
        }
        
        if (b >= c) {
            c *= 2;
            continue;
        }
    }
    
    if (k >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No"  << endl;
    }
    return 0;    
}
