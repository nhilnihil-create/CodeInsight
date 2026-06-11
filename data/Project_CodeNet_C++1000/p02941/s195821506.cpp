#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
ll a[N],b[N],ok[N];
int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) return 0 * printf("-1\n");
        if(a[i]==b[i]) ok[i] = 1;
    }
    queue<int> q;
    for(int i=0;i<n;i++) if(b[i]>=b[(i+1)%n]&&b[i]>=b[(i+n-1)%n]) q.push(i);
    ll ans = 0;
    while(!q.empty()){
        int p = q.front(); q.pop();
        if(ok[p]) continue;
        int x = (p+n-1)%n, y = (p+1)%n;
        if(ok[x]&&ok[y]){
            ll d = b[x]+b[y];
            if((b[p]-a[p])%d) return 0 * printf("-1\n");
            ans += (b[p]-a[p])/d;
            b[p] = a[p], ok[p] = 1;
        }
        else{
            ll mx = 0;
            if(!ok[x]) mx = max(mx,b[x]);
            if(!ok[y]) mx = max(mx,b[y]);
            if(b[p]<mx) continue;
            ll d = b[x]+b[y];
            ans += (b[p]-mx+d-1)/d;
            b[p] -= ((b[p]-mx)+d-1)/d*d;
            while(b[p]>=mx) b[p]-=d, ans++;
            if(b[p]<a[p]) return 0 * printf("-1\n");
            if(b[p]==a[p]) ok[p] = 1;
            q.push(x), q.push(y);
        }
    }
    printf("%lld\n",ans);
}
