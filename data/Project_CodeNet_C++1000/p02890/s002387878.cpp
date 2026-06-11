#include <bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define scd(x) scanf("%d",&x)
#define scdd(x,y) scanf("%d%d",&x,&y)
const int maxn=3e5+10;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
ll arr[maxn],sum[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int n;
    scd(n);
    for(int i=1;i<=n;i++){
        int x;
        scd(x);
        arr[x]++;
        sum[arr[x]]++;
    }
    for(int i=1;i<=3e5;i++)sum[i]+=sum[i-1];
    for(ll i=1;i<=n;i++){
        ll l=0,r=n,ans=0;
        while(r>=l){
            ll mid=(l+r)/2;
            if(i*mid<=sum[mid]){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
}
