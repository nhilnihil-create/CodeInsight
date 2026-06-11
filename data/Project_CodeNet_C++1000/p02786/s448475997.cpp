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
	long long int h;
	cin >> h;

	long long int ans = 0;
	long long int x = 1;
	while (h) {
		h /= 2;
		ans += x;
		x *= 2;
	}
	cout << ans << endl;
}