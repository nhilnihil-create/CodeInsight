#include <bits/stdc++.h>
using namespace std;

int main() {
    
    double N;
    cin >> N;
    int val = ceil(N / 1.08);
    int x = floor(val * 1.08);
    if (x != N) {
        cout << ":(" << endl;
    } else {
        cout << val << endl;
    }
    return 0;
}
