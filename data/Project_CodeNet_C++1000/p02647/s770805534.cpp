#include<iostream>
#include<vector>
using namespace std;
#define maxn 210000
int a[maxn],v[maxn];
int main ()
{   int n,k;
   cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
     while(k--)
     {   for(int i=1;i<=n;i++)
          {   a[max(1,i-v[i])]++;
              a[min(n+1,i+v[i]+1)]--;
		  }
		  for(int i=1;i<n;i++)
		   a[i+1]+=a[i];
		   for(int i=1;i<=n;i++)
		     v[i]=a[i];
		    for(int i=1;i<=n;i++)
		      a[i]=0;
		      int flag=0;
		    for(int i=1;i<=n;i++)
		     {   if(v[i] != n)
		         {  flag=1;break;
				 }
			 }
			 if(!flag) break;
	 }
	for(int i=1;i<=n;i++)
		    cout<<v[i]<<' '; 
			return 0;
}