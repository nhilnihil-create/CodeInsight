#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> cnt(n),isac(n);

	ll ac=0,wa=0;

	for(int i = 0;i<m;i++)
	{
		int p;
		string s;
		cin >> p >> s;
		p--;
		if(isac[p])continue;
		else
		{
			if(s=="AC")
			{
				ac++;
				wa += cnt[p];
				isac[p]=1;
			}
			else
			{
				cnt[p]++;
			}
		}
	}
	cout << ac << ' '<< wa << endl;
}
