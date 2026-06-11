#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N-1; ++i)
	{
		for (int j = 1; j*j <= i; ++j)
		{
			if (i % j == 0)
			{
				if (j * j == i) ans++;
				else ans += 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}