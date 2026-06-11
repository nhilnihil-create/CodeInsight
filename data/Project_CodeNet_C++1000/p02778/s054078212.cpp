//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    string S; cin >> S;

    for (int i = 0; i < S.length(); i++) {
        S[i] = 'x';
    }

    cout << S << endl;
}


int main() {
    solve();
    return 0;
}