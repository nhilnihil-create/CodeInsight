#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int x;
    cin >> x;
    int ret;
    if (x < 600) {
        ret = 8;
    }
    else if (x < 800) {
        ret = 7;
    }
    else if (x < 1000) {
        ret = 6;
    }
    else if (x < 1200) {
        ret = 5;
    }
    else if (x < 1400) {
        ret = 4;
    }
    else if (x < 1600) {
        ret = 3;
    }
    else if (x < 1800) {
        ret = 2;
    }
    else {
        ret = 1;
    }
    cout << ret << endl;
    return 0;
}