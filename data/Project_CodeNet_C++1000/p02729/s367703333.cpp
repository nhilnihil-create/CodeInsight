#include <bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
  cin>>n>>m;
   int i=n*(n-1)/2,j=m*(m-1)/2,ans=0;
   if(i>0)ans+=i;
   if(j>0)ans+=j;
   printf("%d\n",ans);
}
