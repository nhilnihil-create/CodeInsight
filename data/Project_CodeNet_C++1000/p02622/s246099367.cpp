#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
/*int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
//	for(int i=0;i<n;i++) cout<<a[i];
	int sum=0;
	for(int i=n-1;i>1;i--)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i]==a[j]) continue;
			for(int k=j-1;k>=0;k--)
			{
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] < (a[k] + a[j])) 
				{
					sum++;
				}
				
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] >= (a[k] + a[j])) 
				{
					break;
				}
				
			}
		}
	}
	
	cout<<sum;
}

int main()
{
	int n,d,ans=0;
	cin>>n>>d;
	while(n--)
	{
		int a,b; cin>>a>>b;
		long long int fl=a*a + b*b;
		float sum=sqrt(fl);
		if(sum<=d) ans++;
		
	}
	cout<<ans;
}*/
int main()
{
	string s,ss; cin>>s>>ss;
	int ans=0;
	for(int i=0;s[i];i++) if(s[i]!=ss[i]) ans++;
	cout<<ans;
}
