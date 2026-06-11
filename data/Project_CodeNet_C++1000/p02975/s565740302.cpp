#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int bitsum = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        bitsum = bitsum ^ tmp;
    }

    if (bitsum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
