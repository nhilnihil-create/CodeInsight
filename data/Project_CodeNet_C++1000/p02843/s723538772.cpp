#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    if (x%100 <= x/100*5) cout << 1 << endl;
    else cout << 0 << endl;
}