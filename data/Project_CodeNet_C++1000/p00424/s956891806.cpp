#include <cstdio>
int main(){
  char d[3],key[3],val[3],table[256];
  int n,m,i;

  scanf("%d",&n);
  while(n>0){
    for(i=0;i<256;i++) table[i]=i;
    for(i=0;i<n;i++){
      scanf("%s %s",key,val);
      table[key[0]]=val[0];
    };
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%s",d);
      printf("%c",table[d[0]]);
    }
    printf("\n");
    scanf("%d",&n);
  };
  return 0;
};