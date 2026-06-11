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
	int N, K, S;
	cin >> N >> K >> S;
	if (S == mod-7) {
		for (int i = 0; i < K; i++) cout << S << " ";
		for (int i = 0; i < N - K; i++) cout << S - 1 << " ";
	}
	else {
		for (int i = 0; i < K; i++) cout << S << " ";
		for (int i = 0; i < N - K; i++) cout << S + 1 << " ";
	}
}