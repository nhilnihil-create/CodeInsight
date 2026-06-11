#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	string s;
	cin >> s;
	int nb = 0;
	int i = 0;
	while (s[i])
	{
		nb += s[i] - '0';
		i++;
	}
	if (nb % 9 == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return (0);
}
