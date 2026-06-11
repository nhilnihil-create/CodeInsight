#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
int n,k,A[504],sum;
int det[504];
bool check(int x){
    if(sum%x!=0)return 0;
    for(int i=1;i<=n;i++)det[i]=A[i]%x;
    sort(det+1,det+n+1);
    int l=1,r=n;
    ll opc=0;
    while(l<=r){
        if(det[l]%x==0){
            ++l;continue;
        }
        if(det[r]%x==0){
            --r;continue;
        }
        int delta=min(det[l]%x,x-(det[r]%x));
        det[l]-=delta;
        det[r]+=delta;
        opc+=delta;
    }
    return (opc<=k);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    sum=0;
    for(int i=1;i<=n;i++)sum+=A[i];
    int ans=1;
    for(int k=sqrt(sum);k>=1;k--){
        if(check(k))ans=max(ans,k);
        if(check(sum/k))ans=max(ans,sum/k);
    }
    printf("%d\n",ans);
    return 0;
}
