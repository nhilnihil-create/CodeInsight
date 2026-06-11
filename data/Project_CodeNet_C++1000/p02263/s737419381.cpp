#include<stdio.h>
#include<stdlib.h>
main(){
  char op[1000200];
  int memory[100],cnt=0;
  while(scanf("%s",op)!=EOF){
    if(op[0]=='+'){
      memory[cnt-2]+=memory[cnt-1];
      cnt--;
    }else if(op[0]=='-'){
      memory[cnt-2]-=memory[cnt-1];
      cnt--;
    }else if(op[0]=='*'){
      memory[cnt-2]*=memory[cnt-1];
      cnt--;
    }else{
      memory[cnt]=atoi(op);
      cnt++;
    }
  }
  printf("%d\n",memory[0]);
}