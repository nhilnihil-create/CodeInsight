#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(){
  int i,j,k=0,l=0,a=0,b=0;
  char ch;
  char str1[1001]="",str2[1001],str3[1001],str4[1001];
  scanf("%s",str1);
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%s",str2);
    /* printf("%s",str2); */
    if(!strcmp(str2,"replace")){
      /* printf("matched\n"); */
      scanf("%d %d %s",&a,&b,str3);
      for(k=a;k<=b;k++)
        str1[k]=str3[k-a];
    }
    if(!strcmp(str2,"reverse")){
      /* printf("matched\n"); */
      scanf("%d %d",&a,&b);
      for(k=a;k<=b;k++)
        str3[k-a]=str1[k];
      for(k=a;k<=b;k++)
        str1[k]=str3[b-a-k+a];
    }
    if(!strcmp(str2,"print")){
      /* printf("matched\n"); */
      scanf("%d %d",&a,&b);
      for(k=a;k<=b;k++)
        printf("%c",str1[k]);
      printf("\n");
    }
    //    printf("%d %d\n",a,b);
  }
  return 0;
}