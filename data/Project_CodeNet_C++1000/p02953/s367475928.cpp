#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, h[100000], hight;
    bool flg;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> h[i];
    }
    
    flg = true;
    hight = h[0] - 1;
    for ( int i = 1; i < n; i++ ) {
        if ( h[i] < hight ) {
            flg = false;
        } else {
            h[i] = max(h[i]-1, hight);
            hight = max(hight, h[i]);
        }
    }
    
    if ( flg ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return (0);
}
