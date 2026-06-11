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
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;


int main() 
{
	int n;
	cin >> n;
	vector<long long int>a(n);
	rep(i, 0, n)cin >> a[i];
	sort(a.begin(), a.end());
	rep(i, 1, n) {
		if (a[i] == a[i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}

