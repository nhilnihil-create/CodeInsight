#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main()
{
	int K;
	cin >> K;

	queue<long long int>que;
	rep(i, 0, 9)que.push(i + 1);

	while (1)
	{
		long long int x = que.front();
		if (K == 1)
		{
			cout << x << endl;
			return 0;
		}
		for (int i = -1; i <= 1; i++)
		{
			int d = x % 10 + i;
			if (d < 0 || d > 9)continue;
			que.push(x * 10 + d);
		}

		que.pop();
		K--;
	}
	return 0;
}
