#include <bits/stdc++.h>

using namespace std;

char S[4001];
int cnt[4001][3];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> S[i];
		for(int j=0;j<3;j++)
		{
			cnt[i][j] += cnt[i-1][j];
		}
		if(S[i]=='R')
		{
			cnt[i][0] += 1;
		}
		else if(S[i]=='G')
		{
			cnt[i][1] += 1;
		}
		else
		{
			cnt[i][2] += 1;
		}
	}

	long long int res = 0;

	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{
			if((S[j]=='R' && S[k]=='G') || (S[j]=='G' && S[k]=='R'))
			{
				int x = cnt[j-1][2];
				int d = k-j;
				if(j-d>=1)
				{
					if(S[j-d]=='B')
					{
						x--;
					}
				}
				res += x;
			}
			else if((S[j]=='R' && S[k]=='B') || (S[j]=='B' && S[k]=='R'))
			{
				int x = cnt[j-1][1];
				int d = k-j;
				if(j-d>=1)
				{
					if(S[j-d]=='G')
					{
						x--;
					}
				}
				res += x;
			}
			else if((S[j]=='G' && S[k]=='B') || (S[j]=='B' && S[k]=='G'))
			{
				int x = cnt[j-1][0];
				int d = k-j;
				if(j-d>=1)
				{
					if(S[j-d]=='R')
					{
						x--;
					}
				}
				res += x;				
			}
		}
	}

	cout << res << '\n';

	return 0;
}