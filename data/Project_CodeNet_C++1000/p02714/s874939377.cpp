#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main()
{
	int n;
	string s;
	vector<int>R, G, B;
	cin >> n >> s;
	rep(i, 0, n)
	{
		switch (s[i])
		{
		case 'R':R.push_back(i + 1); break;
		case 'G':G.push_back(i + 1); break;
		case 'B':B.push_back(i + 1); break;
		}
	}

	long long int ans;
	ans = R.size() * G.size() * B.size();
	rep(i,0,n)
		rep(j, i, n)
	{
		int k = 2 * j - i;
		if (j <= k && k < n)if (s[i] != s[j] && s[k] != s[j] && s[i] != s[k])ans--;
	}
	cout << ans << endl;
	return 0;
}
