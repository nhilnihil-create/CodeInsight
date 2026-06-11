#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> pl;
	int sum = 0;
	rep(i, n) {
		string tit;
		int tim;
		cin >> tit >> tim;
		sum += tim;
		pl[tit] = sum;

	}
	string x;
	cin >> x;

	int ans = sum - pl[x];
	cout << ans << endl;

	return 0;
}
