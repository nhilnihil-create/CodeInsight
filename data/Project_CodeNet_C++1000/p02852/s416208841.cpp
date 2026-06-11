#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int N, M;
	string S;
	cin >> N >> M >> S;
	vector<int> ans;
	int i = N;
	while (i > 0) {
		//cout << i << endl;
		bool out = true;
		if (i - M <= 0) {
			ans.push_back(i);
			break;
		}
		for (int j = M; j > 0; j--) {
			if (S[i - j] == '0') {
				out = false;
				ans.push_back(j);
				i -= j;
				break;
			}
		}
		if (out) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	cout << endl;
}