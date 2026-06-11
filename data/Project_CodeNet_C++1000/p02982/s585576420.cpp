#include<stdio.h>
#include<math.h>
int main(){
    long long int r,c,i,j,k,co=0,s=0,b;
    scanf("%lld %lld",&r,&c);
    long long int a[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=i+1;j<r;j++){
                s=0;
            for(k=0;k<c;k++){
                s=s+pow((a[i][k]-a[j][k]),2);
            }
            b=sqrt(s);
            if(b*b==s)co++;
        }
    }
    printf("%lld",co);}