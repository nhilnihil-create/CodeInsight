#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int a,b;
	cin >> a >> b;
	if (a <= b+b) cout << 0;
	else cout << a - (b+b);

	return (0);
}