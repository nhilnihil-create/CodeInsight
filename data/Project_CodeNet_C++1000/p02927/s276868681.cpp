#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int m,d;
    cin >> m >> d;
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= d; j++) {
            int ten = j / 10;
            int one = j % 10;
            if(ten < 2 || one < 2) {
                continue;
            }
            if(ten * one == i) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}