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

LL a[maxn];

int main() {
    int n;
    sd(n);
    rep(i,1,n) {
        slld(a[i]);
    }
    sort(a+1,a+n+1);
    LL ans = a[n];
    int res = n - 2;
    per(i,n-1,1) {
        if(res <= 0) break;
        if(res == 1) {
            ans += a[i];
            res--;
        } else {
            ans += a[i] * 2;
            res -= 2;
        }
    }
    plld(ans);
    return 0;
}