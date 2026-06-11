#include <bits/stdc++.h>
using namespace std;


int main(){
   int n,ans=1,k;
   cin>>n;
   for(int i=0;i<n;i++){
       scanf("%d",&k);
       if(k%2==0){
           if(k%5>0&&k%3>0){ans=0;break;}
       }
   }
   if(ans)printf("APPROVED\n");
   else printf("DENIED\n");
}