#include <bits/stdc++.h>

using namespace std;

long long int psumA[200001];
long long int psumB[200001];
int A[200001],B[200001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m,k;

	cin >> n >> m >> k;

	for(int i=1;i<=n;i++)
	{
		cin >> A[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin >> B[i];
	}

	for(int i=1;i<=n;i++)
	{
		psumA[i] = psumA[i-1] + A[i];
	}
	for(int i=1;i<=m;i++)
	{
		psumB[i] = psumB[i-1] + B[i];
	}

	int res = 0;

	for(int i=0;i<=n;i++)
	{
		if(psumA[i] > k)
		{
			break;
		}
		int lo = 0;
		int hi = m;
		int Max = 0;
		long long int val = k - psumA[i];
		while(lo<=hi)
		{
			int mid = (lo + hi)/2;
			if(psumB[mid] <= val)
			{
				Max = max(Max,mid);
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		res = max(res,i + Max);
	}

	cout << res << '\n';

	return 0;
}