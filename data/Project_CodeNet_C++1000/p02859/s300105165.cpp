#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;
#define pi 3;
int  main()
{
	int r;
	cin >> r;
	int x = 1;
	int area = r*r*pi;
	int xarea = x*x*pi;
	cout << area / xarea << endl;
	// cout << area;
	return (0);
}