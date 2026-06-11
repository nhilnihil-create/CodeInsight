#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(sqrt(pow(x, 2) + pow(y, 2)) <= D) {
            ans++;
        }
    }
    cout << ans;
}