#include<bits/stdc++.h>
using namespace std;
 
int main(){
        long long  int n;
         cin>>n;
         long long int i,s=0,j;
         for(i=1;i<=n;i++)
         {
                  for(j=i;j<=n;j=j+i)
                {  s=s+j;
                  
                }
         }
cout<<s<<endl;
}