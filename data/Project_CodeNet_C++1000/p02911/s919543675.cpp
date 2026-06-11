#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N, K, Q;
    cin >> N >> K >> Q;
    map<int, int>d;
    for (int64_t i=0; i<Q; i++) {
        int64_t A;
        cin >> A;
        if (d.count(A) > 0) {
            d[A] = d[A] + 1;
        } else {
            d[A] = 1;
        }
    }
    int64_t score = K - Q;
    for (int64_t i=0; i < N; i++) {
        if (d.count(i+1) > 0) {
            if (score + d[i+1] > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            if (score > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}