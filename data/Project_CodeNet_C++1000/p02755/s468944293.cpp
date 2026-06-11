#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, ans = -1;
    cin >> x >> y;
    for(int i = 10; i <= 1009; i++) {
        if((i*8)/100 == x && i/10 == y) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
