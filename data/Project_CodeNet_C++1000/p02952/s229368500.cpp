#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int count = 1;
		int tmp = i;
		while (true)
		{
			if (tmp<10)
			{
				break;
			}
			count++;
			tmp /= 10;
			
		}
		if (count%2==1)
		{
			ans++;
		}
	}
	cout << ans << endl;
}