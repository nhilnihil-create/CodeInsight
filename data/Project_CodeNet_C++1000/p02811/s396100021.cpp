//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int K, X; cin >> K >> X;
    int sum = 500 * K;
    cout << (sum >= X ? "Yes" : "No") << endl;
}


int main() {
    solve();
    return 0;
}