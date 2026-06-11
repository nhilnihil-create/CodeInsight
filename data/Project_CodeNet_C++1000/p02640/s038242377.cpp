#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int x,y;
    bool check = false;
    cin >> x >> y;
    rep(i,x+1) {
        if (y == (((x-i)*2) + (i*4))) {
            check = true;
            break;
        }
    }
    if (check) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}