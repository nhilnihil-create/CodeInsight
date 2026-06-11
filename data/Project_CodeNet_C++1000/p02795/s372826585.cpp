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
	int h, w, n;
	cin >> h >> w >> n;
	int ans = 0;
	if (h > w) {
		while (n>0) {
			ans++;
			n -= h;
		}
	}
	else {
		while (n>0) {
			ans++;
			n -= w;
		}
	}
	cout << ans << endl;
}