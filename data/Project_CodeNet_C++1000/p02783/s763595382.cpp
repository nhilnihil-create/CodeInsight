#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, a;
    cin >> h >> a;
    for(int i; true; i++) {
        if(h <= a * i) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}