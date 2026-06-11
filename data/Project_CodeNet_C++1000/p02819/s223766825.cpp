#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int X;
    cin >> X;
    while (true) {
        int cnt = X;
        bool prime = true;
        for(int i = 2; i*i <= cnt; i++) {
            if(cnt%i == 0) {
                prime = false;
            }
        }
        if(prime) {
            cout << cnt << endl;
            break;
        }
        X++;
    }
}
