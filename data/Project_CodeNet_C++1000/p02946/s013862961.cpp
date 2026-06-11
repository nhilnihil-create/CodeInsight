#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int k, x; cin >> k >> x;
	int s;
	int end = x + (k - 1);
	for (s = x - (k - 1); s <= end; s++)
	{
		if (s >= (-1000000) && s <= 10000000)
			cout << s << " ";
	}
	cout << endl;
	return (0);
}