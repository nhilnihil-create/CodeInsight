#include <bits/stdc++.h>
using namespace std;
string a,last;
int ans;
int main()
{
	cin>>a;
	last.push_back(a[0]);
	ans++;
	for (int i=1;i<(int)a.size();)
	{
		ans++;
		if (i==(int)a.size()-1)
		{
			if (a.substr(i,1)==last) ans--;
			break;
		}
		if (a.substr(i,1)==last) last=a.substr(i,2),i+=2;
		else last=a.substr(i,1),i++;
	}
	printf("%d\n",ans);
}