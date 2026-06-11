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

int H[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = N - 1; i > 0; i--) {
		if (H[i - 1] - H[i] >= 2) {
			cout << "No" << endl;
			return 0;
		}
		if (H[i - 1] > H[i]) H[i - 1]--;
	}
	cout << "Yes" << endl;
}