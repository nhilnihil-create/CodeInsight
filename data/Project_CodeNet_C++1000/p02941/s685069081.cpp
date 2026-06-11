#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int a[maxn],b[maxn],n,ans;
priority_queue<pii > q;

signed main() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    for(int i=1;i<=n;i++) if(b[i]>a[i]) q.push(mp(b[i],i));
    while(!q.empty()) {
        int x=q.top().sc;q.pop();
        int p=b[(x-1)?x-1:n]+b[x%n+1],t=0;
        // printf("%d %d\n",x,b[x]);
        ans+=(t=(b[x]-a[x])/p),b[x]-=t*p;
        if(!t) return puts("-1"),0;
        if(b[x]>a[x]) q.push(mp(b[x],x));
        // if(b[x]<a[x]) return puts("-1"),0;
        // printf("%d %d\n",x,b[x]);
    }write(ans);
    return 0;
}
