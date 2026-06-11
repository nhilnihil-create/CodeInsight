#include <cstdio>
#include <cstring>
bool s[33];
int main(void){
  memset(s,true,sizeof(s));
  for(int i = 0; i < 28; i++){
    int n;
    scanf("%d",&n);
    s[n]=false;
  }
  for(int i = 1; i <= 30; i++){
    if(s[i])printf("%d\n",i);
  }
}