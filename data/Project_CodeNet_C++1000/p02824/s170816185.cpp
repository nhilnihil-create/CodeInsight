#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int a[maxn];
int cmp(const int a,const int b){
    return a>b;
}
int n,m,v,p;
int b[maxn];
bool judge(int mid){
    //printf("hello %lld\n",mid);
    if(mid<=p)return true;
    if(a[mid]+m<a[p])return false;
    if(v<=p-1&&a[mid]+m>=a[p])return true;
    for(int i=1;i<=n;i++)b[i]=a[i];
    int temp=0;
    int inx=n,cnt=v-p+1;
    for (int i=n,j=v-p;i>mid&&j;i--,j--){
        temp+=m;
        b[i]+=m;
    }
    temp+=m*p;
    int now=a[mid]+m;
    int res=m*v-temp;
    int ww=a[p];
    for(int i=p;i<mid;i++){
        int add=min(m,max(now-a[i],0ll));
        if(add>res)add=res;
        res-=add;
        b[i]+=add;
        if(i==p){
            ww+=add;
        }
    }
    return now>=ww&&res<=0;
}
signed main(){
    cin>>n>>m>>v>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int low=1,high=n;
    int ans=0;
    while(low<=high){
        int mid=(low+high)>>1;
        if(judge(mid)){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}