#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, X;
    cin >> K >> X;
    int sum = 500 * K;
    string messages = "No";
    if(X <= sum) {
        messages = "Yes";
    }
    cout << messages << endl;
    return 0;
}