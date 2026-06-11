#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
 
using namespace std;
typedef long long ll;
string a,b;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	ll cnt=b.size();
	if (a==b)
	cout<<"0"<<endl;
	else 
	{
		for (ll i=0;i<a.size();i++)
		{
			ll ans=b.size();
			if (i+b.size()<=a.size())
			{
				for (ll j=i;j<i+b.size();j++)
				{
					//cout<<a[j]<<' '<<a[i]<<endl; 
					if (a[j]==b[j-i])
					ans--;
				}
			}
			//cout<<ans<<endl;
			cnt=min(cnt,ans);
		}
		cout<<cnt<<endl;
	}
	return 0;
}