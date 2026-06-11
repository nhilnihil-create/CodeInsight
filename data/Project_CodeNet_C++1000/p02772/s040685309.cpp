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
#define INF 1000000007
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, 0, n)cin >> a[i];
	bool ans = true;
	rep(i, 0, n) {
		if (a[i] % 2==0) {
			if (a[i] % 3 > 0 && a[i] % 5 > 0) {
				ans = false;
				break;
			}
		}
	}
	if (ans)cout << "APPROVED" << endl;
	else cout << "DENIED" << endl;
}

