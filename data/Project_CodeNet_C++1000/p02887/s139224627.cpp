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
#define INF 1001001001001001001
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	rep(i, 1, n)
		if (s[i] == s[i - 1])ans++;
	cout << n - ans << endl;
}
