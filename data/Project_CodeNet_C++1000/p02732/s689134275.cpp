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

vector<int>a[200000];

int main()
{
	int N,x;
	cin >> N; 
	vector<int>b(N+1);
	rep(i, 0, N)
	{
		cin >> x;
		a[x].push_back(i+1);
		b[i + 1] = x;
	}
	int s;
	long long int ans = 0, ansx;
	rep(i, 0, N)
	{
		ans += a[i + 1].size() * (a[i + 1].size() - 1) / 2;
	}
	rep(i, 0, N)
	{
		ansx = ans;
		s = a[b[i + 1]].size();
		ansx = ansx - s * (s - 1) / 2 + (s - 1) * (s - 2) / 2;
		cout << ansx << endl;
	}

	return 0;
}
