#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; 
long long n,m,a[200010],b[200010],k,ans,s,x;
int main()
{
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){cin>>x;a[i]=a[i-1]+x;}
   for(int i=1;i<=m;i++){cin>>x;b[i]=b[i-1]+x;}
   for(int i=0;i<m;i++)b[i]=b[i+1];
   vector<long long> v(b,b+m);
   
   for(int i=0;i<=n;i++)
   {
       if(a[i]<=k)
       {s=i;
       if(k<b[0])x=0;
       else
       x=upper_bound(v.begin(),v.end(),k-a[i])-v.begin();
           
       }
       else
       break;
      
       ans=max(ans,x+s);
   }
   
   cout<<ans<<endl;
    
}