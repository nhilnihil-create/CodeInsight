#define _CRT_SECURE_NO_WARNINGS 1

#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define rep(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; i--)
#define mem(a) memset(a,0,sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int maxn = 2e5 + 7;

int main() {
    int n;
    sd(n);
    LL ans = 1LL * n * (n + 1) * (n + 2) / 6;
    rep(i,1,n-1) {
        int u, v;
        sd(u), sd(v);
        LL x = min(u,v) , y = max(u,v);
        ans -= x * (n - y + 1);
    }
    plld(ans);
    return 0;
}