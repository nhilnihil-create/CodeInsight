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
#include<complex>
#include<fstream>
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

//
int main()
{
	long long int n;
	int k;
	cin >> n >> k;

	int ans = 0;
	while (n) {
		n /= k;
		ans++;
	}
	cout << ans;
}