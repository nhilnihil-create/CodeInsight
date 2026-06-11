#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);   
	ll n,a[200009],m,k,ans=0,ct=0,fl=0;
	string s,s1="";
	cin>>s>>n;
	for(int i=0;i<n;i++)
	{
		ll u,v;
		string p;
		cin>>u;
		if(u==1)
			ct++;
		else
		{
			cin>>v>>p;
			if(ct%2==0)
			{
				if(v==2)
					s+=p;
				else
					s1+=p;
			}
			else
			{
				if(v==1)
					s+=p;
				else
					s1+=p;
			}
		}
	}
	if(ct%2==0)
	{
		reverse(s1.begin(),s1.end());
		cout<<s1<<s<<endl;
	}
	else
	{
		reverse(s.begin(),s.end());
		cout<<s<<s1<<endl;
	}
	return 0;
}