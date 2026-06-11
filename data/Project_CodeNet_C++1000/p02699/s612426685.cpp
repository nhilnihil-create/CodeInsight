#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int S, W;
    cin >> S >> W;
    if (W >= S) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
    return 0;
}
