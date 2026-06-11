#include <stdio.h>
int n,k,a[1000010];
bool check(int ans){
    int now=0,t=0;
    for(int i=0;i<n;i++){
        if(now+a[i]>ans){
            t++;
            now=0;
        }
        now+=a[i];
    }
    
    return t<k;
}
int main(){
    int top=0,tot=0,mid;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>top)top=a[i];
        tot+=a[i];
    }
    while(tot-top>1){
        mid=(tot+top)/2;
        if(check(mid))tot=mid;
        else top=mid;
    }
    if(check(top))printf("%d\n",top);
    else printf("%d\n",tot);
}