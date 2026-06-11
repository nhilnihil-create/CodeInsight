/*
 * Author       : YangDavid
 * Created Time : 2019年07月14日 星期日 22时36分08秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 111111;
int n;
vector<pii> e;

set<int> adj1;
void add(int x, int y) { e.emplace_back(x, y); }

int main() {
    scanf("%d", &n);
    if(__builtin_popcount(n) == 1) {
        puts("No");
        return 0;
    }
    puts("Yes");
    add(3, 2);
    add(2, 1);
    add(1, n + 3);
    add(n + 3, n + 2);
    add(n + 2, n + 1);
    int c = 3;
    while(c + 2 <= n) {
        add(1, c + 1);
        add(c + 1, c + 2);
        add(1, n + c + 2);
        add(n + c + 2, n + c + 1);
        c += 2;
    }
    if(c < n) {
        int k = 1;
        while(k <= n) k <<= 1;
        k >>= 1;
        add(n, k);
        int to = n ^ 1 ^ k;
        if(to & 1) to += n;
        add(n * 2, to);
    }

    for(auto g : e)
        printf("%d %d\n", g.first, g.second);
    
    return 0;
}
