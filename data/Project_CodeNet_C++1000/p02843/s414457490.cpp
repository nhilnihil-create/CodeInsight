#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int long long

signed main() {
    int x;
    cin >> x;

    for(int i = 0; i <= x; i++) {
        if(i * 100 <= x && x <= i * 105) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}