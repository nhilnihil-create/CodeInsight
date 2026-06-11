#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,s;
int solve(int se,int no,int sum){
  if(no>=n){
    if(sum==s) return 1;
    else return 0;
  } 
  if(se>=10) return 0;
  return solve(se+1,no,sum)+solve(se+1,no+1,sum+se);
}
main(){
  while(1){
    int res;
    scanf("%d %d",&n,&s);
    if(n==0 && s==0) break;
    res=solve(0,0,0);
    printf("%d\n",res);
  }
}