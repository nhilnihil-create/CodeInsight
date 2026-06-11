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
	int x;
	cin >> x;
	int a = x % 100;
	int b = (x - a) / 100;
	rep(i, 0, 1000) {
		if ( a+100*i <= 5 * (b-i)) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}
