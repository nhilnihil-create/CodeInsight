#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, P> T;

const ll mod = 1000000007;
const ll INF = 1000000100;

ll N, x[101], y[101];
vector<T> vec[2];
vector<ll> A, B;

double ans;

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
	}
}

void output()
{
	printf("%.12f", ans);
}

void solve(ll a, ll b)
{
	ll X = 0, Y = 0;

	for (int i = 0; i < N; i++)
	{
		if (a * x[i] + b * y[i] > 0)
		{
			X += x[i], Y += y[i];
		}
	}

	ans = max(ans, sqrt(pow(X, 2) + pow(Y, 2)));
}

int main()
{
	init();

	for (int i = 0; i < N; i++)
	{
		if (x[i] * y[i] > 0)
		{
			vec[0].push_back(T((double)y[i] / x[i], P(abs(x[i]), abs(y[i]))));
		}
		else
		{
			vec[1].push_back(T((double)y[i] / x[i], P(-abs(x[i]), abs(y[i]))));
		}
	}

	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());

	if (vec[0].size() > 0)
	{
		A.push_back(vec[0][0].second.first + 1);
		B.push_back(vec[0][0].second.second);
		A.push_back(vec[0][vec[0].size() - 1].second.first);
		B.push_back(vec[0][vec[0].size() - 1].second.second + 1);
	}

	for (int i = 1; i < vec[0].size(); i++)
	{
		A.push_back(vec[0][i - 1].second.first + vec[0][i].second.first);
		B.push_back(vec[0][i - 1].second.second + vec[0][i].second.second);
	}

	if (vec[1].size() > 0)
	{
		A.push_back(vec[1][0].second.first);
		B.push_back(vec[1][0].second.second + 1);
		A.push_back(vec[1][vec[1].size() - 1].second.first - 1);
		B.push_back(vec[1][vec[1].size() - 1].second.second);
	}

	for (int i = 1; i < vec[1].size(); i++)
	{
		A.push_back(vec[1][i - 1].second.first + vec[1][i].second.first);
		B.push_back(vec[1][i - 1].second.second + vec[1][i].second.second);
	}

	for (int i = 0; i < A.size(); i++)
	{
		solve(B[i], -A[i]);
		solve(-B[i], A[i]);
	}

	output();

	cin >> N;
}