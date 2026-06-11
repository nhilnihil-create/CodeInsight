#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
int n;
int num[N][N], pos[N][N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1, x; j < n; j++) {
            cin >> x;
            num[i][j] = x;
            pos[i][x] = i*n+j;
            // printf("pos[%d][%d]:%d\n", i, x, i*n+j);
        }
    }

    set<int> s, s2;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        s2.insert(pos[i][num[i][1]]);
        if(s2.count(pos[num[i][1]][i])) {
            s2.erase(pos[i][num[i][1]]);
            s2.erase(pos[num[i][1]][i]);
            s.insert(pos[i][num[i][1]]);
        }
    }
    // for(int x : s) {
    //     cout << ":" << x << endl;
    // }
    // for(int x : s2) {
    //     cout << ">" << x << endl;
    // }

    while(!s.empty()) {
        set<int> new_s;
        for(int t : s) {
            int x = t/n, y = t%n;
            int t2 = pos[num[x][y]][x];
            y++;
            if(y != n) {
                s2.insert(pos[x][num[x][y]]);
                if(s2.count(pos[num[x][y]][x])) {
                    s2.erase(pos[x][num[x][y]]);
                    s2.erase(pos[num[x][y]][x]);
                    new_s.insert(pos[x][num[x][y]]);
                }
            }
            x = t2/n; y = t2%n;
            y++;
            if(y != n) {
                s2.insert(pos[x][num[x][y]]);
                if(s2.count(pos[num[x][y]][x])) {
                    s2.erase(pos[x][num[x][y]]);
                    s2.erase(pos[num[x][y]][x]);
                    new_s.insert(pos[x][num[x][y]]);
                }
            }
        }
        ans++;
        s = new_s;
    }

    if(s2.size()) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}