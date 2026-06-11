#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int n,m,v,p,x,y,z;
 cin>>n>>m>>v>>p;
 long long int a[n];
 long long int s[n];
 int i;
 for(i=0;i<n;i++)
 {
 	cin>>a[i];
 }
 sort(a,a+n,greater<long long int> ());
 int ans=p;
 s[p-1]=0;
 for(i=p;i<n;i++)
 {
 	s[i]=s[i-1]+a[p-1]-a[i];
 	//cout<<s[i]<<endl;
 }
 for(i=p;i<n;i++)
 {
 	x=m*v-m*(p+n-i-1);
 	if(x>0)
 	{
 	 	x-=s[i-1];
 	 	if(x>0)
 	 	{
 	 	 if(x%(i-p+1)==0)
		   {
		   	y=a[p-1]+x/(i-p+1);
		   	if(y>(a[i]+m))
		   	break;
		   	else
		   	ans++;
		   }
		  else
		  {
		  	y=a[p-1]+x/(i-p+1)+1;
		   	if(y>(a[i]+m))
		   	break;
		   	else
		   	ans++;
		  }	
		}
		else
		{
			if(a[i]+m>=a[p-1])
			ans++;
			else
			break;
		}
	}
	else
	{
		if((a[i]+m)>=a[p-1])
		ans++;
		else
		break;
	}
 }
 cout<<ans<<endl;
 return 0;
}
