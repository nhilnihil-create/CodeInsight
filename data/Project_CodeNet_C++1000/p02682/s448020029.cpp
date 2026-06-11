#include <bits/stdc++.h>
using namespace std;

int main(){
   int a,b,c,k,i,ans;
   scanf("%d %d %d %d",&a,&b,&c,&k);
   if(k<=a)ans=k;
   else if(k<=a+b)ans=a;
   else ans=2*a+b-k;
   printf("%d\n",ans);
}