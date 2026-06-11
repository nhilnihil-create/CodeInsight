#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

char str[200005];

void solve()
{
    int n, a, b, c, d;
    scanf("%d%d%d%d%d%s", &n, &a, &b, &c, &d, str); a--; b--; c--; d--;
    int i;
    if (c > d) {
        for (i = a + 1; i < b; i++) {
            if (str[i] == '#' && str[i - 1] == '#') {
                printf("No\n"); return;
            }
        }
        for (i = d + 1; i < c; i++) {
            if (str[i] == '#' && str[i - 1] == '#') {
                printf("No\n"); return;
            }
        }
        int bad = 1;
        for (i = b; i <= d; i++) {
            if (str[i+1] == '.' && str[i]=='.' &&  str[i - 1] == '.') {
                bad = 0;
            }
        }
        if (bad) {
            printf("No\n"); return;
        }
    }
    else {
        for (i = a + 1; i < c; i++) {
            if (str[i] == '#' && str[i - 1] == '#') {
                printf("No\n"); return;
            }
        }
        for (i = b + 1; i < d; i++) {
            if (str[i] == '#' && str[i - 1] == '#') {
                printf("No\n"); return;
            }
        }
    }
    printf("Yes\n");
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
