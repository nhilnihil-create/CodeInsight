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
	int a, b, c;
	cin >> a >> b >> c;
	bool ans = 0;
	if (a == b || b == c || c == a)ans = true;
	if (a == b && b == c && c == a)ans = false;
	if (ans)cout << "Yes" << endl;
	else cout << "No" << endl;
}

