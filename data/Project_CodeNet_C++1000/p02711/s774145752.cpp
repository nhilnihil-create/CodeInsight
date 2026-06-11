#include<stdio.h>
int main()
{ int n;
    scanf("%d",&n);

        if(n%10==7 || (n%100>=70 && n%100<=79) || (n%1000>=700 && n%1000<800))
           printf("Yes");
      else printf("No");




}