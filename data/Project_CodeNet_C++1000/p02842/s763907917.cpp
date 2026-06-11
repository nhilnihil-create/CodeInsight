#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int X = int(N * 100 / 108);
    if (int(X * 1.08) == N) {
        cout << X << endl;
    } else if (int((X+1) * 1.08) == N) {
        cout << X + 1 << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}