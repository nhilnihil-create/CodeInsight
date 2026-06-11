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
	bool flag = true;
	if (n % 2==0) {
		rep(i, 0, n / 2) {
			if (s[i] != s[n / 2 + i]) {
				flag = false;
				break;
			}
		}
	}
	else {
		flag = false;
	}

	if (flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}
