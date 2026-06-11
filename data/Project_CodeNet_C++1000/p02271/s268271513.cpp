#include<stdio.h>

int a[200],b;
int a_num,b_num,j=0;

int solve(int, int);
int main()
{

  int b_num,i,j = 0;


  scanf("%d",&a_num);
  for(i = 0;i < a_num; i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&b_num);
  for(i = 0;i < b_num; i++){
    scanf("%d",&b);
    j = 0;
    if(solve(j,b) == 1){
      printf("yes\n");
    }
    if(solve(j,b) == 0){
      printf("no\n");   
    }
  }
  
  return 0;
}


int solve(int i,int m)
{
  int res;
  if(m == 0)return 1;
  if(i >= a_num)return 0;
  res = solve(i+1,m) || solve(i+1,m-a[i]);
}
      