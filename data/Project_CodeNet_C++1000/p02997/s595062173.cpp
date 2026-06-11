#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N,K;
	cin >> N >> K;
	int M = (N-1)*(N-2)/2;
	if (K > M)
	{
		cout << "-1" << endl;
		return 0;
	}
	int ans = N-1 + (M-K);
	int cnt = M-K;
	cout << ans << endl;
	rep(i,N-1)
	{
		cout << 1 << " " << i+2 << endl;
	}
	int c = 1;
	while (cnt)
	{
		if ((N-1) % c == 0 && (N-1) / c == 2)
		{
			rep(j,(N-1)/2)
			{
				cout << j+2 << " " << (j+c)%(N-1)+2 << endl;
				cnt--;
				if (cnt == 0) break;
			}
			c++;
		}
		else
		{
			rep(j,N-1)
			{
				cout << j+2 << " " << (j+c)%(N-1)+2 << endl;
				cnt--;
				if (cnt == 0) break;
			}
			c++;
		}
	}
	return 0;
}