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
	long long int h, w;
	long long int ans;
	cin >> h >> w;
	if (h % 2 == 1 && w % 2 == 1)ans = (h * w)/2 + 1;
	else ans = (h * w)/2;
	if (h == 1 || w == 1)ans = 1;
	cout << ans << endl;
}
