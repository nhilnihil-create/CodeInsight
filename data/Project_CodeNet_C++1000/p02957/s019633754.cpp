#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	long a,b; cin >> a >> b;
	long g = max(a,b);
	long ans = -1;
	for (int i = 0; i <= g; i++)
	{
		if (labs(a-i) == labs(b-i))
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << endl;
	return (0);
}