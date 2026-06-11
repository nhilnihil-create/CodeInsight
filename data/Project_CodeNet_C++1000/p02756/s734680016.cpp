#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char H[200005],T[200005];

int main()
{
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	bool rev = false;
	string temp = S;
	int cntH = 0, cntT = 0;
	rep(i,Q)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			if (rev) rev = false;
			else rev = true;
		}
		else
		{
			int f;
			char c;
			cin >> f >> c;
			if (!rev)
			{
				if (f == 1)
				{
					H[cntH] = c;
					cntH++;
				}
				else
				{
					T[cntT] = c;
					cntT++;
				}
			}
			else
			{
				if (f == 1)
				{
					T[cntT] = c;
					cntT++;
				}
				else
				{
					H[cntH] = c;
					cntH++;
				}
			}
		}
	}
	if (rev)
	{
		rep(i,cntT)
		{
			cout << T[cntT-1-i];
		}
		reverse(S.begin(), S.end());
		cout << S;
		rep(i,cntH)
		{
			cout << H[i];
		}
	}
	else
	{
		rep(i,cntH)
		{
			cout << H[cntH-1-i];
		}
		cout << S;
		rep(i,cntT)
		{
			cout << T[i];
		}
	}
	cout << endl;
	return 0;
}