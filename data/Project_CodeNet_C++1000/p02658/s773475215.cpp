#include<bits/stdc++.h>
using namespace std;
#define maxn 1e18
long long a[100005],b[250],len,c[250];
/*void sr()
{
	string str1,str2;
	cin>>str1>>str2;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[0]=str1.length();
	for(int i=1;i<=a[0];i++)
	{
		a[i]=str1[a[0]-i]+1-'0';
	}
	b[0]=str2.length();
	for(int i=1;i<=b[0];i++)
	{
		b[i]=str2[b[0]-i]+1-'0';
	}
}
void jiafa()
{
	len=max(a[0],b[0]);
	for(int i=1;i<=len;i++)
	{
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	len++;
	while(a[len]==0&&(len>1))len--;
	for(int i=len;i>=1;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void cf()
{
	memset(c,0,sizeof(c));
	for(int i=1;i<=a[0];i++)
	{
		for(int j=1;j<=b[0];j++)
		{
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	len=a[0]+b[0]+1;
	while((c[len]==0)&&(len>1))len--;
	for(int i=len;i>=1;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
}*/
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
	   }
	   for(int i=0;i<n;i++)
	   {
	   	if(a[i]==0)
	   	{
		   cout<<"0"<<endl;
	   	return 0;	
		   }
	   	
	   }
	   long long sum=1;
	   for(int i=0;i<n;i++)
	   {
	   	if(a[i]<=1000000000000000000/sum)
	   	{
	   		sum*=a[i];
		   }
		   else
		   {
		   	cout<<"-1"<<endl;
		   	return 0;
		   }
			} 
			cout<<sum<<endl;    
} 
