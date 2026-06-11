#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int s,w;
    cin >> s >> w;

    if (w >= s) {
        cout << "unsafe" << endl;
    }
    else {
        cout << "safe" << endl;
    }
    return 0;
}