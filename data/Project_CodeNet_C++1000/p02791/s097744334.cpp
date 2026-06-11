#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() 
{
	int n;
	cin >> n;
	int x = 200001, ans = 0;
	rep(i, 0, n) {
		int p;
		cin >> p;
		if (p <= x) {
			ans++;
			x = p;
		}
	}
		cout << ans << endl;
}


