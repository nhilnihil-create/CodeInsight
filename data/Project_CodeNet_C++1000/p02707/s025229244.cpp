#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> A(n);

    for (size_t i = 1; i < n; i++) {
        int ai;
        cin >> ai;
        ++A[--ai];
    }

    for (size_t i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
    return 0;
}
