#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#define INF 2e9
#define rep(i,m) for(int i=0;i<m;i++)
#define repn(i,n,m) for(int i=n;i<m;i++)


using namespace std;

int main()
{
	string a;
	cin >> a;

	rep(i, size(a))
	{
		if (a[i] == '?')a[i] = 'D';
	}
	cout << a << endl;
	return 0;
}
	