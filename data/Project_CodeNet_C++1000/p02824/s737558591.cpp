#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n,m,v,p,a[100010];

bool calc(int mid,ll cnt=0){
    int x=a[mid]+m;
    if(a[p-1]>x)return false;
    cnt+=(ll)(p-1)*m;
    cnt+=(ll)(n-mid)*m;
    for(int i=p-1; i<=mid-1; ++i){
        cnt+=min(m,max(0,x-a[i]));
    }
    return cnt>=(ll)m*v;
}

int main(){
    cin>>n>>m>>v>>p;
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    int l=0,r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        if(calc(mid))l=mid;
        else r=mid;
    }
    //1-indexedに修正
    cout<<l+1<<endl;
}