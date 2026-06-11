#include <stdio.h>
int main(){
    int a[3][3]={0}, i, j, k;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int n, m;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&m);
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                if(a[j][k]==m){ a[j][k]=0; }
            }
        }
    }
    int flag=0;
    for(i=0; i<3; i++){
        if( a[i][0]==0 && a[i][1]==0 && a[i][2]==0 ){ flag=1; }
        if( a[0][i]==0 && a[1][i]==0 && a[2][i]==0 ){ flag=1; }
    }
    if( a[0][0]==0 && a[1][1]==0 && a[2][2]==0 ){ flag=1; }
    if( a[0][2]==0 && a[1][1]==0 && a[2][0]==0 ){ flag=1; }
 
    if( flag ){ printf("Yes\n"); }
    else      { printf("No\n");  }
    return 0;
}