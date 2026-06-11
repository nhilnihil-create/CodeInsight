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
	int a, b;
	bool flag = 0;
	a = n / 1.08;
	rep(i, 0, 10) {
		int x = (a + i) * 1.08;
		if (n == x) {
			cout << a + i << endl;
			flag = true;
			break;
		}
	}
	if(!flag)cout << ":(" << endl;

}
