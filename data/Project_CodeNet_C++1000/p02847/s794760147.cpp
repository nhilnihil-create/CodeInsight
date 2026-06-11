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
#include<ctime>
#include<cstdlib>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() {
	vector<string>s{ "SUN","MON","TUE","WED","THU","FRI","SAT" };
	string t;
	cin >> t;
	rep(i, 0, 7) {
		if (t == s[i]) {
			cout << 7 - i << endl;
		}
	}
	
}
