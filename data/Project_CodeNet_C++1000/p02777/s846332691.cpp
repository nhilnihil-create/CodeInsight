#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 20;
char s[N], t[N], u[N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    scanf("%s %s\n%d %d\n%s", s, t, &a, &b, u);
    int n = strlen(s), m = strlen(t), sz = strlen(u);
    if (sz == n && sz == m) {
        for (int i = 0; i < sz; i++) {
            if (s[i] != u[i]) {
                b--;
                goto con;
            }
        }
        a--;
    } else if (sz == n) {
        a--;
    } else {
        b--;
    }
    con:;
    printf("%d %d", a, b);
    return 0;
}
