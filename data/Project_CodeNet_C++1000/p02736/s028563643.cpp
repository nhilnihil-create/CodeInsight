#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> v;
	for (char c:s)
	v.push_back(c-'0');
	for (int i=0;i<n-1;i++)
	v[i]=abs(v[i]-v[i+1]);
	v.pop_back();
	n--;
	if (count(v.begin(),v.end(),1))
	{
		for (int &i:v)
		i%=2;
	}
	for (int i=0;i<20;i++)
	{
		if ((n-1)&(1<<i))
		{
			vector<int> tmp;
			for (int j=0;j+(1<<i)<v.size();j++)
			tmp.push_back(v[j]^v[j+(1<<i)]);
			v=tmp;
		}
	}
	cout << v[0];
}