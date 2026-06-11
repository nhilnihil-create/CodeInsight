#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,ans=0;
	for(int i=0;i<2;i++)
	{
		cin>>a;
		if(a==1)ans+=300000;
		else if(a==2)ans+=200000;
		else if(a==3)ans+=100000;
	}
	if(ans==600000)ans+=400000;
	cout<<ans<<endl;
	return 0;
}