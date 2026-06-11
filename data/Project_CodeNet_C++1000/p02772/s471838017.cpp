#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	
		int n;
		cin>>n;
		vector<int> a(n+1);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
			{
				if(a[i]%3!=0 && a[i]%5!=0)
				{
					flag=1;
				}
			}
		}

		if(flag)
		{
			cout<<"DENIED"<<endl;
		}
		else
		{
			cout<<"APPROVED"<<endl;
		}




	
	return 0;
}	