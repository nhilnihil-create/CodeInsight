#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, r;
	cin >> n >> r;
	if (n>=10)
		cout << r << endl;
	else
		cout << r + (100 * (10 - n)) << endl;
	return (0);
}
