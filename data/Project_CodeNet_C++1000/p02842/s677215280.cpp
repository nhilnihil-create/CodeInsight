
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main()
{
	cout << setprecision(20);
	double N;
	cin >> N;
	int M, L;
	M = N / 1.08;
	L = M + 1;
	int S = M * 1.08;
	int T = L * 1.08;
	if (S==N || T==N)
	{
		if (S==N)
		{
			cout << M <<  endl;
		}else{
			cout << L << endl;
			}
	}
	else {
		cout << ":(" << endl;
	}
}