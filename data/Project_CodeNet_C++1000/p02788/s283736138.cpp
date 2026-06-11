#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

const int maxn = 2e5 + 7;
const int INF = 0x3f3f3f3f;

struct node {
    int pos,val;
}a[maxn];

bool cmp(node aa,node bb) {
    return aa.pos < bb.pos;
}

LL q[maxn];

int main() {
    int n,d,x;
    scanf("%d%d%d",&n,&d,&x);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d%d",&a[i].pos,&a[i].val);
    }
    d <<= 1;
    sort(a+1,a+n+1,cmp);
    LL ans = 0;
    for(int i = 1 ; i <= n ; i++) {
        q[i] += q[i-1];
        a[i].val -= q[i] * x;
        if(a[i].val <= 0) continue;
        LL temp = (a[i].val + x - 1) / x;
        ans += temp;
//        cout << "i = " << i << " ans = " << ans << endl;
        q[i] += temp;
        int l = i , r = n;
        int res = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
//            cout << "l = " << l << " r = " << r << " " << a[mid].pos << " " << a[i].pos + d << endl;
            if(a[mid].pos <= a[i].pos + d) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
//        cout << "res = " << res << endl;
        q[res+1] -= temp;
    }
    printf("%lld\n",ans);
    return 0;
}
