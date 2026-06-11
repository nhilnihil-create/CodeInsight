#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 100005, MAX = 1000000000;
char s[N];
int dp[N], nxt[N];

int main() {
    int n, m;
    scanf("%d %d\n%s", &n, &m, s);
    set <pair <int, int> > st;
    dp[n] = 0;
    nxt[n] = -1;
    st.insert({dp[n], n});
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = MAX;
        nxt[i] = -1;
        if (s[i] == '0') {
            auto it = st.begin();
            if (it->fi + 1 < dp[i]) {
                dp[i] = it->fi + 1;
                nxt[i] = it->se;
            }
        }
        st.insert({dp[i], i});
        if ((int)st.size() > m) {
            st.erase({dp[i+m], i+m});
        }
    }
    if (dp[0] == MAX) {
        printf("-1");
    } else {
        int x = nxt[0], pre = 0;
        while (x != -1) {
            printf("%d ", x - pre);
            pre = x;
            x = nxt[x];
        }
    }
    return 0;
}
