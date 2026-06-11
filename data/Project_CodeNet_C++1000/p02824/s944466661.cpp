#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn],n,m,v,p;
int l,r,mid;
bool check(int x){
    ll t=v-(p-1)-1-(x-1);
    ll sum=0;
    for (int i=x+1;i<=n-(p-1);i++) {
        if (a[x]+m<a[i]) return 0;
        sum+=a[x]+m-a[i];
    }
    return sum>=t*m;
}
int main(){
    cin >> n >> m >> v >> p;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    l=0; r=n;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << n-l << endl;
    return 0;
}
