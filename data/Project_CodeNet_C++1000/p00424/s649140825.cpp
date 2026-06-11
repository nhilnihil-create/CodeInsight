#include<stdio.h>
int main(){
 while(1){
        int a,b;
        char aa[100],bb[100],d,dd[10000000];
        scanf("%d",&a);
 if(a==0) break;
        for(int i=0;i<a;i++) scanf(" %c %c",&aa[i],&bb[i]);
        scanf("%d",&b);
        for(int i=0;i<b;i++)
        {
                scanf(" %c",&dd[i]);
                for(int j=0;j<a;j++){
                        if(dd[i]==aa[j])
                        {printf("%c",bb[j]);
                         break;
                        }
if(j==(a-1)) printf("%c",dd[i]);
               }
      }
        printf("\n");
}
return 0;
}