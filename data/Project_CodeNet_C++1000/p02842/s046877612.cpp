#include <bits/stdc++.h>
using namespace std;

int main() {
    long long price;
    vector<double> vec;
    cin >> price;

    for (int i = 1; i <= 50000; i++) {
        vec.push_back(static_cast<long long>(i * 1.08));
    }

    for (int i = 0; i < 50000; i++) {
        if (vec[i] == price) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}