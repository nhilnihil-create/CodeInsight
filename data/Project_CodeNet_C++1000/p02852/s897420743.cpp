#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> ans;

int main()
{
	int N,M;
	cin >> N >> M;
	string S;
	cin >> S;
	int i = N;
	while (i > 0)
	{
		int temp;
		if (i - M < 0) temp = 0;
		else temp = i - M;
		bool flag = false;
		while (temp != i)
		{
			if (S[temp] == '0')
			{
				ans.push_back(i - temp);
				i = temp;
				flag = true;
				break;
			}
			temp++;
		}
		if (!flag)
		{
			 cout << "-1" << endl;
			 return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	rep(i,ans.size())
	{
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}