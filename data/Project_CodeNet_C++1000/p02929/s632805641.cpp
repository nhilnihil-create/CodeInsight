#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define LL long long
#define lowbit(x) x &(-x)
template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(y < x) x = y;}
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
char c[N];
long long ans = 1;
int sum = 0, a[N], n;//left : 0  \\ right : 1

int main() {   
    n = read(); 
    scanf("%s", c);
    a[1] = 0; sum = 1;
    if(c[0] == 'W') {
        cout << 0 << endl;
        return 0;
    }
    REP(i, 2, 2 * n) {
        if(a[i - 1]) {
            if(c[i - 1] == c[i - 2]) a[i] = 0;
            else a[i] = 1;
        } else {
            if(c[i - 1] == c[i - 2]) a[i] = 1;
            else a[i] = 0;
        }
        if(a[i]) {
            ans = ans * sum % mod;
            sum --;
        } else sum ++;
    }
    if(sum) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, 2, n) ans = ans * i % mod;
    printf("%lld\n", ans);
	return 0;
}
