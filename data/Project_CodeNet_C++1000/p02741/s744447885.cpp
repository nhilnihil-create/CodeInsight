#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",&x)
#define rep(i,a,b) for(int i = a ; i <= b ; i++)
#define per(i,a,b) for(int i = b ; i >= a ; i--)
#define mem(a) memset(a,0,sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const LL INF = 1e12;
const int mod = 1e4 + 7;
const int maxn = 2e5 + 7;

int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main() {
    int k;
    while(~sd(k)) {
        pd(a[k-1]);
    }
    return 0;
}
