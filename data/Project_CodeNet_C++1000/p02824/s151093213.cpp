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

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int a[maxn],n,m,v,p,f[maxn];

int gao(int x) {
    while(a[x+1]==a[x]) x++;
    int r=lower_bound(a+1,a+n+2,a[x]+m+1)-a;
    r=n-r+1;int g=v-r-(x-1)-1;
    if(g<=0&&r<=p-1) return 1;
    g*=m;f[x]=0;
    for(int i=x+1;i+r<=n;i++) {
        f[i]=a[x]+m-a[i];
        f[i]+=f[i-1];
    }
    int ans=n-x;
    for(int i=n-r;i>x;i--)
        if((n-r-i)*m+f[i]>=g) ans=min(ans,n-i);
    return ans<=p-1;
}

signed main() {
    read(n),read(m),read(v),read(p);
    for(int i=1;i<=n;i++) read(a[i]);a[n+1]=2e9;
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++) printf("%d ",a[i]);
    int l=1,r=n,ans=n;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(gao(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    write(n-ans+1);
    return 0;
}
