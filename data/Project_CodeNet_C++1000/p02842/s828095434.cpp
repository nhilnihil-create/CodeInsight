#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x;
    y = int((100 * x)/108);
    for(int i = 1; i <= 46297; i++) {
        if((i*108)/100 == x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}
