#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int h,w,a,b;
	cin >> h >> w >> a >> b;
	vector<string> ans(h);
	for(int i = 0;i<h;i++)
		for(int j = 0;j<w;j++)ans[i].push_back('0');

	swap(a,b);




	for(int i = 0;i<a;i++)
		for(int j = 0;j<b;j++)
			ans[i][j]++;
	
	
	for(int i = a;i<h;i++)
		for(int j = b;j<w;j++)
			ans[i][j]++;
	for(int i = 0;i<h;i++)cout<<ans[i]<<endl;
	return 0;
}
