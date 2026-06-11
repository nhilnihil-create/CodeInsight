#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
int n;
int num[N][N], pos[N][N];
void add(set<int>& s, set<int>& s2, int i, int j) {
    s2.insert(pos[i][num[i][j]]);
    if(s2.count(pos[num[i][j]][i])) {
        s2.erase(pos[i][num[i][j]]);
        s2.erase(pos[num[i][j]][i]);
        s.insert(pos[i][num[i][j]]);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1, x; j < n; j++) {
            cin >> x;
            num[i][j] = x;
            pos[i][x] = i*n+j;
        }
    }

    set<int> s, s2;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        add(s, s2, i, 1);
    }

    while(!s.empty()) {
        set<int> new_s;
        for(int t : s) {
            int x = t/n, y = t%n;
            int t2 = pos[num[x][y]][x];
            y++;
            if(y != n) {
                add(new_s, s2, x, y);
            }
            x = t2/n; y = t2%n;
            y++;
            if(y != n) {
                add(new_s, s2, x, y);
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