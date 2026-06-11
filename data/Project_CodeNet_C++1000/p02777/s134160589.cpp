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



int main() {
	string s, t, u;
	int x, y;
	cin >> s >> t;
	cin >> x >> y >> u;
	if (u == s)cout << x - 1 << " " << y << endl;
	else cout << x << " " << y - 1 << endl;
}


