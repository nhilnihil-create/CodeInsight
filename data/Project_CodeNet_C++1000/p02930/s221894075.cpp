#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 500010
#define mod 1000000007
int p[510][510];
void sol(int l,int r,int x){
    if(l==r) return;
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++){
        for(int j=mid+1;j<=r;j++){
            p[i][j]=x;
        }
    }
    sol(l,mid,x+1);
    sol(mid+1,r,x+1);
}
int main(){
    int n;
    scanf("%d",&n);
    sol(1,n,1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++) printf("%d ",p[i][j]);
        printf("\n");
    }
    // if(n>=1){
    //     for(int i=1;i<=n;i++){
    //         if(i%3==0) p[i]=3;
    //         else p[i]=i%4;
    //     }
    // }
    // else{
    //     for(int i=1;i<n;i++){
    //         if(p[i])continue;
    //         cnt++;
    //         for(int j=i;j<n;j+=2*cnt){
    //             p[j]=cnt;
    //         }
    //     }
    // }
    // for(int i=n-1;i>0;i--){
    //     for(int j=1;j<=i;j++)printf("%d ",p[j]);
    //     printf("\n");
    // }
    return 0;
}