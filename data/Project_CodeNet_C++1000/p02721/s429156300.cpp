/**   
 *   Author:    @glaucoacassioc
 *   Created on 11.09.2020, 15:32:16
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dp[200002];
int mx[200002];
string s;
int n, k, c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k >> c;
	cin >> s;
	s = ' ' + s;
	for(int i=n; i>=1; i--)
	{
		if(s[i] == 'o')
			dp[i] = 1 + mx[min(n+1, i + c + 1)];
		else
			dp[i] = mx[i+1];
		mx[i] = max(dp[i], mx[i+1]);
	}
	int mxr = k;
	int lst = 1;
	int bgrm = 0;
	deque<int> v;
	while(mxr)
	{
		for(int i = lst; i<=n; i++)
			if(s[i] == 'o' && dp[i] >= mxr)
				v.push_back(i);
			else
			{
				if(mx[i] < mxr)
				{
					lst = i;
					break;
				}
			}
		if(v.size() == 1)
			cout << v[0] << endl;
		if(v.size())
			lst = max(lst, v[0] + c + 1);
		int prv_val = v[0];
		while(!v.empty() && prv_val + c + 1 > v[0])
			v.pop_front();
		--mxr;
	}
	return 0;
}             
