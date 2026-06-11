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
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i * j == N) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}