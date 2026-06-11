#include<stdio.h>
char a[21][21];
int c;
void dfs(int y,int x){
  c++;
  a[y][x]=0;
  if(y!=0)
    if(a[y-1][x]=='.')
      dfs(y-1,x);
  if(y!=20)
    if(a[y+1][x]=='.')
      dfs(y+1,x);
  if(x!=0)
    if(a[y][x-1]=='.')
      dfs(y,x-1);
  if(x!=20)
    if(a[y][x+1]=='.')
      dfs(y,x+1);
}
int main(){
  int w,h,i,j;
  char b[21];
  while(1){
    scanf("%d%d",&w,&h);
    if(w==0&&h==0)break;
    for(i=0;i<21;i++){
      for(j=0;j<21;j++){
	a[i][j]=0;
      }
    }
    for(i=0;i<h;i++){
	scanf("%s",b);
	for(j=0;b[j]!='\0';j++){
	  a[i][j]=b[j];
	}
    }
    c=0;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(a[i][j]=='@')dfs(i,j);
      }
    }
    printf("%d\n",c);

   
  }
  return 0;
}