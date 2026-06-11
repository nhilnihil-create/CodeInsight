#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#define INF 2e9
#define rep(i,m) for(int i=0;i<m;i++)
#define repn(i,n,m) for(int i=n;i<m;i++)


using namespace std;

int main()
{
	int a, b, c, d, x;
	cin >> a >> b >> c >> d >> x;

	int ans;
	ans = (c - a) * 60 + d - b - x;
	cout << ans << endl;
	return 0;
}