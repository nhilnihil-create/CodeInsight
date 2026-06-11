#include<bits/stdc++.h>
using namespace std;

#define LL long long
struct Q{char x; int a, b, c, d;} a[2001][2001];
int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j].x;

    for(int i = 1; i <= n; i++) {
        int cur = 1;
        for(int j = 1; j <= m; j++) {
            a[i][j].a = cur;
            if(a[i][j].x == '#') cur = j + 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        int cur = m;
        for(int j = m; j >= 1; j--) {
            a[i][j].b = cur;
            if(a[i][j].x == '#') cur = j - 1;
        }
    }

    for(int j = 1; j <= m; j++) {
        int cur = 1;
        for(int i = 1; i <= n; i++) {
            a[i][j].c = cur;
            if(a[i][j].x == '#') cur = i + 1;
        }
    }

    for(int j = 1; j <= m; j++) {
        int cur = n;
        for(int i = n; i >= 1; i--) {
            a[i][j].d = cur;
            if(a[i][j].x == '#') cur = i - 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(a[i][j].x == '.') ans = max(ans, a[i][j].b - a[i][j].a + 1 + a[i][j].d - a[i][j].c + 1 - 1); //if(i == 2 && j == 3) cout << a[i][j].a << a[i][j].b << a[i][j].c << a[i][j].d;
        }
    cout << ans;    
}