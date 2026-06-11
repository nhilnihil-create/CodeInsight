#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int a,b; cin >> a >> b;

	b *= 2;
	if (a <= b)
		cout << 0 << endl;
	else
		cout << a - b << endl; 
	return (0);
}