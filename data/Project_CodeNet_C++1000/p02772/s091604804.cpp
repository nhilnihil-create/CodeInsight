#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    bool approved = true;
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            if (n % 3 != 0 && n % 5 != 0) {
                approved = false;
                break;
            }
        }
    }

    if (approved) {
        cout << "APPROVED" << endl;
    } else {
        cout << "DENIED" << endl;
    }
    return 0;
}