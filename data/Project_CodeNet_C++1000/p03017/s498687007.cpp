#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> intpair;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= MOD ? x + y - MOD: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}
template<typename T>
T gcd(T a, T b){
    return (!b) ? a: gcd(b, a % b);
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD, b >>= 1;
    }
    return res;
}
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/

int n, a, b, c, d;
char s[200005];
bool nec[200005] = {0}, nec2[200005] = {0};
void init(){
    n = read(), a = read(), b = read(), c = read(), d = read();
    scanf("%s", s);
}
void solve(){
    --a, --b, --c, --d;
    // 无连续
    bool flag = true;
    REP(i, b + 1, d){
        if (s[i] == s[i - 1] && s[i] == '#'){
            flag = false;
            break;
        }
    }
    if (!flag){
        printf("No\n");
        return ;
    }
    REP(i, a + 1, c){
        if (s[i] == s[i - 1] && s[i] == '#'){
            flag = false;
            break;
        }
    }
    if (!flag){
        printf("No\n");
        return ;
    }
    if (c > d){
        nec[a] = nec[c] = true;
        REP(i, a + 1, c){
            if (s[i] == '#'){
                nec[i + 1] = nec[i - 1] = true;
            }
        }
        nec2[b] = nec2[d] = true;
        REP(i, b + 1, d){
            if (s[i] == '#'){
                nec2[i + 1] = nec2[i - 1] = true;
            }
        }
        int cntb = 0;
        REP(i, b, d) if (nec2[i] || s[i] == '#') ++cntb;
        if (cntb == d - b + 1){
            // 全部必须
            bool flag2 = true;
            REP(i, a, c){
                if (nec2[i] && !nec[i]){
                    flag2 = false;
                    break;
                }
            }
            if (flag2){
                printf("No\n");
            }else {
                printf("Yes\n");
            }
        }else {
            printf("Yes\n");
        }
    }else {
        printf("Yes\n");
    }
}
int main(){
    init();
    solve();
    return 0;
}