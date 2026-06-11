#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6;
int a[N]; ll s[N];
int main(){
    int n,m,v,p; scanf("%d%d%d%d",&n,&m,&v,&p);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n),reverse(a+1,a+1+n);
    rep(i,1,n) s[i]=s[i-1]+a[i];
    int ans=p;
    rep(i,p+1,n){
        int v0=v-(p-1)-(n-i+1);
        if (a[p]>a[i]+m) break;
        else if (v0<0) ++ans;
        else if ((ll)(m+a[i])*(i-p)-(s[i-1]-s[p-1])>=(ll)v0*m) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
