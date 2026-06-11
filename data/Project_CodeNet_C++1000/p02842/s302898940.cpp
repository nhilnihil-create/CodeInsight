#include <bits/stdc++.h>
using namespace std;

int main() {
    double N;
    cin >> N;

    if (ceil(N / 1.08) < ceil((N + 1) / 1.08)) {
        cout << ceil(N / 1.08) << endl;
        return 0;
    }
    cout << ":(" << endl;
}