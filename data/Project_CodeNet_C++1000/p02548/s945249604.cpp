#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
// #include<queue>
#include<vector>
#include<utility>
using namespace std;
int inf=1e9;
//vector<long long int>adj[10000];

int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		//int a=i;
		int b=(n-1)/i;
		//int c=n-(n-1)*b;
		ans+=b;
		// if(a>0 && b>0 && c>0)
		// {
		// 	if(a==b && b==c)ans+=1;
		// 	else if((a==b && b!=c) || (a==c && a!=b) || (b==c && a!=b))ans+=3;
		// 	else ans+=6;
		// }
		//cout<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
