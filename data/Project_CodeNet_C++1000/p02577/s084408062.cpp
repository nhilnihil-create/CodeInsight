#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    string N; cin >> N;
    int su = 0;
    for (int i = 0; i < N.size(); i++) {
        int num = (int)(N[i] - '0');
        su += num;
    }
    if (su%9 == 0 || su == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
