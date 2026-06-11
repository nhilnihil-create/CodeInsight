#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, x, t;
	cin >> n >> x >> t;
	int nb;
	if (n % x == 0)
		nb = n / x;
	else
		nb = n / x + 1;
	cout << nb * t << endl;
	return (0);
}
