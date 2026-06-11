#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    string N; cin >> N;
    int su = 0;
    for (int i = 0; i < N.size(); i++) {
        su += N[i] - '0';
    }
    if (su%9) cout << "No\n";
    else cout << "Yes\n";
}
