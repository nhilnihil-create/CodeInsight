#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define mem(i, a) memset(i, a, sizeof(i))
#define sqr(x) ((x)*(x))
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
typedef long long ll;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 7;
using namespace std;
char s[maxn];
int l[maxn], r[maxn];
int main(void){
#ifdef ljxtt
freopen("data.in", "r", stdin);
#endif
    int n, k, c;
    scanf("%d%d%d%s", &n, &k, &c, s + 1);
    for(int i = 1, m = 0, next = 0; i <= n && m < k; i++){
        if(i > next && s[i] != 'x'){
            l[m++] = i;
            next = i + c;
        }
    }
    for(int i = n, m = k - 1, next = n + 1; i >= 1 && m >= 0; i--){
        if(i < next && s[i] != 'x'){
            r[m--] = i;
            next = i - c;
        }
    }
    for(int i = 0; i < k; i++){
        // printf("%d %d\n", l[i], r[i]);
        if(l[i] == r[i] && l[i] != 0) printf("%d\n", l[i]);
    }
    return 0;
}    