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
	int L;
	cin >> L;
	cout <<fixed<< (double)(L * L * L / 3.0 / 3.0 / 3.0) << endl;
	return 0;
}