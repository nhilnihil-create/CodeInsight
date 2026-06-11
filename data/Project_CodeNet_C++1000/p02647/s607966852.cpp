#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 200005;
int A[MAX_N];

int main()
{
	int N,K;
	cin >> N >> K;
	rep(i,N)
	{
		cin >> A[i];
	}
	rep(i,K)
	{
		vector<pair<int,int> > B;
		rep(j,N)
		{
			B.push_back(make_pair(j-A[j],1));
			B.push_back(make_pair(j+A[j]+1,-1));
		}
		sort(B.begin(), B.end());
		int cnt = 0;
		int idx = 0;
		bool allN = true;
		for (int j = 0; j < N; ++j)
		{
			while(idx < B.size() && B[idx].first <= j)
			{
				if (B[idx].second == 1)
				{
					cnt++;
					idx++;
				}
				else
				{
					cnt--;
					idx++;
				}
			}
			A[j] = cnt;
			if (cnt != N) allN = false;
		}
		if (allN)
		{
			rep(j,N)
			{
				if (j != 0) cout << " ";
				cout << N;
			}
			cout << endl;
			return 0;
		}
	}

	rep(i,N)
	{
		if (i != 0) cout << " ";
		cout << A[i];
	}
	return 0;
}