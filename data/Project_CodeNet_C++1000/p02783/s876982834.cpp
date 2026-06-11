#include<bits/stdc++.h>
using namespace std;

int H, A;

int main() {
    cin >> H >> A;
    if (A >= H) { cout << 1 << endl; return 0; }
    int cnt = 0;
    while (H > 0) {
        H -= A;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
