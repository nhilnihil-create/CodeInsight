#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N.length(); i++) {
        sum += N[i] - '0';
    }
    cout << (sum % 9 == 0 ? "Yes" : "No") << endl;
    return 0;
}