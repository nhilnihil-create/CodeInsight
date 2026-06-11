#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, r, d;
    cin >> l >> r >> d;
    
    int counter = 0;
    
    for (int i = l; i <= r; ++i) {
        if (i % d == 0) ++counter;
        else continue;
    }
    
    cout << counter << "\n";
    
    return 0;
}
