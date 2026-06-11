#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int loop(int,int[],int,int);

int main(){
   int n,s;
   int ans;
   int flag[10];
   int kaijyo;
   
   for(;;){
      cin>>n>>s;
      if(n==0&&s==0) break;
      
      memset(flag,0,sizeof(flag));
      ans=0;
      kaijyo=1;
      for(int i=n;i>0;i--) kaijyo*=i;
      
      ans = loop(ans,flag,n,s);
      
      cout<<ans/kaijyo<<endl;
   }
   return 0;
}

int loop(int ans,int flag[],int n, int s){

   if(n==0){
      if(s==0) ans++;
      return ans;
   }
   
   int i;
   for(i=0;i<10;i++){
      if(s-i>=0&&flag[i]!=1){
         flag[i]=1;
         ans = loop(ans,flag,n-1,s-i);
         flag[i]=0;
      }
   }
   return ans;
}