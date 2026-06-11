#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N;
	cin >> N;
	long long cnt = 0;
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(1ll*i*j < N)
				cnt++;
			else
				break;
		}
	}
	cout << cnt;
}


int main() {
    int t;
    // cin>>t;
	// while(t--)
		solve();
	return 0;

}