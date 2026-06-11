#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
int np[MAX_N],p[MAX_N];

int main()
{
	int N;
	cin >> N;
	int cntp = 0,cntnp = 0;
	rep(i,N)
	{
		int a;
		cin >> a;
		if (a > 0)
		{
			p[cntp] = a;
			cntp++;
		}
		else
		{
			np[cntnp] = a;
			cntnp++;
		}
	}

	sort(np,np+cntnp);
	sort(p,p+cntp);
	int sump = 0, sumnp = 0;
	rep(i,cntp)
	{
		sump += p[i];
	}
	rep(i,cntnp)
	{
		sumnp += np[i];
	}
	if (cntnp >= 1 && cntp >= 1)
	{
		cout << sump - sumnp << endl;
		rep(i,cntp-1)
		{
			cout << np[0] << " " << p[i] << endl;
			np[0] -= p[i];
		}

		rep(i,cntnp)
		{
			cout << p[cntp-1] << " " << np[i] << endl;
			p[cntp-1] -= np[i]; 
		}
		//cout << p[cntp-1] << endl;
		return 0;
	}
	else if (cntnp == 0)
	{
		cout << sump - p[0] * 2 << endl;
		rep(i,cntp-2)
		{
			cout << p[0] << " " << p[i+1] << endl;
			p[0] -= p[i+1];
		}

		cout << p[cntp-1] << " " << p[0] << endl;
		//cout << p[cntp-1] - p[0] << endl;
	}
	else
	{
		cout << sumnp * (-1) + np[cntnp-1] * 2 << endl;
		rep(i,cntnp-1)
		{
			cout << np[cntnp-1] << " " << np[i] << endl;
			np[cntnp-1] -= np[i];
		}
		//cout << np[cntnp-1] << endl;
	}
	return 0;
}