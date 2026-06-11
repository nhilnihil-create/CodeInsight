#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool a = A == B;
    bool b = B == C;
    bool c = A == C;
    int sum = 0;
    if (a) sum++;
    if (b) sum++;
    if (c) sum++;
    if (sum == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}