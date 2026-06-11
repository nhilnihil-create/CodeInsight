#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

signed main()
{
	int N;
	cin >> N;
	vector<pair<string, int>>v(N);
	rep(i, N)
	{
		string s;
		int t;
		cin >> s >> t;
		v[i] = make_pair(s, t);
	}
	string X;
	cin >> X;
	int num;
	rep(i, N)if (v[i].first == X)num = i;
	int sum = 0;
	for (int i = num + 1; i < N; i++)sum += v[i].second;
	cout << sum;
}