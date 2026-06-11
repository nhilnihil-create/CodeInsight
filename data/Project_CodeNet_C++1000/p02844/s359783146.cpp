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
	vector<char>s(n);
	rep(i, 0, n)cin >> s[i];

	int ans = 0;
	bool flag100, flag10;
	rep(i, 0, 1000) {
		flag100 = 0; flag10 = 0;
		rep(j, 0, n) {
			int x = s[j] - '0';
			if (!flag100)
				if (x == (i - i % 100) / 100) {
					flag100 = true;
					continue;
				}
			if (flag100 == true && flag10 == false)
				if (x == (i % 100 - i % 10) / 10) {
					flag10 = true;
					continue;
				}
			if (flag100 == true && flag10 == true)
				if (x == i % 10) {
					ans++;
					break;
				}
		}
	}
	cout << ans << endl;
}


