#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;

    for (int i = 0; i < k*2-1; i++) {
        cout << x-k+1+i;
        if (i != k*2-2) cout << ' ';
        else cout << endl;
    }
}