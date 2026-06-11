#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>
#include <set>
#include <bitset>
#define ls x<<1
#define rs x<<1|1
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(x) scanf("%d", &x)
#define scdd(x,y) scanf("%d%d", &x, &y)
#define scddd(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define eb emplace_back
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define IOS std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = 2*acos(0.0);
const double eps = 1e-13;
const ll mod = 1e9+7;
const int maxn = 1e5 + 10;
const int maxm = 50000 + 10;

int a[maxn], stk[maxn], l[maxn], r[maxn];
void solve() {
    int n;
    scd(n);
    int top=0;
    for(int i=1; i<=n; i++) {
        scd(a[i]);
        while(top>0 && a[stk[top-1]] < a[i]) top--;
        stk[top++] = i;
        if(top==1) l[i]=0;
        else l[i]=stk[top-2];
    }

    top=0;
    for(int i=n; i>0; i--){
        while(top>0 && a[stk[top-1]] < a[i]) top--;
        stk[top++] = i;
        if(top==1) r[i]=n+1;
        else r[i] = stk[top-2];
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        if(l[i]!=0){
            int ll=l[i]-1;
            while(1){
                if(a[ll]>a[i] || ll==0) break;
                ll--;
            }
            int f1=l[i]-ll;
            int f2=r[i]-i;
            ans += 1LL*a[i]*f1*f2;
        }
        if(r[i]!=n+1){
            int rr=r[i]+1;
            while(1){
                if(a[rr]>a[i] || rr==n+1) break;
                rr++;
            }
            int f1=i-l[i];
            int f2=rr-r[i];
            ans += 1LL*a[i]*f1*f2;
        }
    }
    printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
#endif
    //IOS;
    solve();

    return 0;
}
