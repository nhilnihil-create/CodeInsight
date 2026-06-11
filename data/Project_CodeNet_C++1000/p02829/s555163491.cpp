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
	vector<bool>a(3,0);
	int x, y;
	cin >> x >> y;
	a[x - 1] = true;
	a[y - 1] = true;
	rep(i, 0, 3)if (!a[i])cout << i + 1 << endl;
}