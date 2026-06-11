#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i= 0; i <b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}

//x < yで管理
map<pairII, int> Color;

int GetColor(int x, int y) {
	if (x > y)
		swap(x, y);
	
	return Color[make_pair(x, y)];
}

int main() {
	int i, j, k;

	int N, M, K;

	vector<int> A[100001];
	pairII edge[100000];
	int parentColor[100001] = { 0 };
	cin >> N;
	rep(i, 0, N-1) {
		pairII a;
		cin >> a.first >> a.second;
		if (a.first > a.second)
			swap(a.first, a.second);
		edge[i] = a;
		Color[a] = -1;
		A[a.first].push_back(a.second);
		A[a.second].push_back(a.first);
	}

	queue<int> Q;
	Q.push(1);
	parentColor[1] = -1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		int color = 0;
		for (auto y : A[x]) {
			if (parentColor[y] != 0)continue;

			color++;
			if (color == parentColor[x])
				color++;
			parentColor[y] = color;
			
			int s = x, t = y;
			if (s > t)swap(s, t);
			Color[make_pair(s, t)] = color;

			Q.push(y);

		}




	}
	
	K = 0;
	rep(i, 1, N+1) {
		K = max(parentColor[i], K);
	}
	cout << K << endl;
	rep(i, 0, N - 1) {
		cout << Color[edge[i]]<<endl;
	}
	return 0;
}