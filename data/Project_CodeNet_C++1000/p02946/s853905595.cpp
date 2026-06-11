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
	int K, X;
	cin >> K >> X;
	for (int i = X - K + 1; i < X + K; i++) {
		cout << i << " ";
	}
	cout << endl;
}