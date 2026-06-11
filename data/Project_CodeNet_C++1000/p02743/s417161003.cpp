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
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;
	if (a + b >= c)
	{
		cout << "No" << endl;
		return 0;
	}
	if (4 * a * b < c * c + (a + b) * (a + b) - 2 * (a + b) * c)cout << "Yes" << endl;
	else cout << "No" << endl; 
}
