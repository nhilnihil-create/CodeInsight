#include<bits/stdc++.h>
using namespace std;
#define loop(i,x,z) for (int i=x;i<z;i++)
using ll = long long;
int n, h[200002];
vector<int>neg[200002], ad[200002];
ll ans = 0;
int main()
{
	cin >> n;
	loop(i, 1, n+1)cin >> h[i];
	loop(i, 1, n + 1)
	{
		if (i + h[i] < 200002)ad[i + h[i]].push_back(i);
		if (i - h[i] > 0)neg[i - h[i]].push_back(i);
	}
	loop(i, 1, 200001)ans += ad[i].size() * neg[i].size();
	cout << ans;
}