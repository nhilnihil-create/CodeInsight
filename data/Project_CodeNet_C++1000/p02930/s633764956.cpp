/*
 * Author       : YangDavid
 * Created Time : 2019年08月24日 星期六 23时34分01秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 555, N = 512;
int G[maxn][maxn];
int main() {
    for(int lv = 1; lv <= 9; ++lv) {
        int d = 1 << (lv - 1);
        for(int i = d; i < 2 * d; ++i)
            for(int j = i + 1; j < 2 * d; ++j)
                G[i][j] = G[i - d][j - d];
        for(int i = 0; i < d; ++i)
            for(int j = d; j < 2 * d; ++j)
                G[i][j] = lv;
    }
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j)
            printf("%d%c", G[i][j], " \n"[j == n - 1]);
    }
    return 0;
}
