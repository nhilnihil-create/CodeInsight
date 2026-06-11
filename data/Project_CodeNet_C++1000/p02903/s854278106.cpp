#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	int h,w,a,b;
	cin >> h >> w >> a >> b;
	vector<string> s(h);
	for(int i =0;i<h;i++)
	{
		for(int j =0;j<w;j++)
		{
			s[i].push_back('0');
		}
	}
	for(int i = 0;i<b;i++)
	{
		for(int j = 0;j<a;j++)
		{
			s[i][j] = '1';
		}
	}
	for(int i = b;i<h;i++)
	{
		for(int j = a;j<w;j++)
		{
			s[i][j] = '1';
		}
	}
	for(int i =0;i<h;i++)cout<<s[i]<<endl;
	return 0;
}