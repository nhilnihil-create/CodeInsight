#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        float a[n];
        int i;
        for(i=0;i<n;i++){
            scanf("%f",&a[i]);
        }
        float sum=0,ave;
        for(i=0;i<n;i++){
            sum+=a[i];
        }
        ave=sum/n;
        float nbunsan=0,bunsan;
        for(i=0;i<n;i++){
            nbunsan+=(a[i]-ave)*(a[i]-ave);
        }
        bunsan=nbunsan/n;
        float hensa;
        hensa=sqrt(bunsan);
        printf("%f\n",hensa);
        scanf("%d",&n);
    }
    return 0;
}