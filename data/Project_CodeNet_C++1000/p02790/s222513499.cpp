//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    char a, b; cin >> a >> b;

    string aa, bb;
    for (int i = 0; i < b - '0'; i++) {
        aa += a;
    }
    for (int i = 0; i < a - '0'; i++) {
        bb += b;
    }

    if (aa < bb) cout << aa << endl;
    else cout << bb << endl;
}


int main() {
    solve();
    return 0;
}