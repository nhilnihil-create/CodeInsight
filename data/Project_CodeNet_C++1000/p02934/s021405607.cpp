#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	vector<int> a(n);
	vector<double> A(n);
	double sum = 0;
	rep(i, n)
	{
		cin >> a[i];
		A[i] = (double)1 / a[i];
		sum += A[i];
	}
	double ans = (double)1 / sum;
	printf("%.14f\n", ans);
	return (0);
}
