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
#define INF  int(1e6+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>>a(n);
	rep(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	int x = 1, ans = 0, now = 0;
	rep(i, 0, n){
		if (a[i].first == x) {
			if (a[i].second > now) {
				now = a[i].second;
				ans++;
				x++;
			}
		}
	}
	if (ans == 0)cout << -1 << endl;
	else cout << n - ans << endl;
}


