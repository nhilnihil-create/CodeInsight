//#pragma warning(disable:4996)
//#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
template<class T>
using V = vector<T>;
template<class T>
using VV = vector<vector<T>>;
typedef unsigned long long ULL;

void input();
void solve();

void daminput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////


int N;
VLL X;
VLL Y;

void input() {
	cin >> N;
	X.resize(N);
	Y.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
	}
}

void daminput() {
}

void argsort(V<PLL>& points) {
	V<pair<PLL, int>> P(points.size());
	for (int n = 0; n < points.size(); n++)
	{
		P[n] = pair<PLL, int>(points[n], n);
	}
	auto dot = [](PLL a, PLL b) {
		return a.first * b.first + a.second * b.second;
	};
	auto cross = [](PLL a, PLL b) {
		return a.first * b.second - a.second * b.first;
	};
	auto deg = [&](PLL a) {
		int e1acr = cross(PI(1, 0), a);
		int e1adot = dot(PI(1, 0), a);
		if (e1adot > 0 && e1acr >= 0)return 1;
		else if (e1adot <= 0 && e1acr > 0)return 2;
		else if (e1adot < 0 && e1acr <= 0)return 3;
		else return 4;
	};
	auto comp = [&](pair<PLL, int> ap, pair<PLL, int> bp) {
		PLL a = ap.first;
		PLL b = bp.first;
		if (a.first == 0 && a.second == 0) {
			if (b.first == 0 && b.second == 0)return ap.second < bp.second;
			else return true;
		}
		if (b.first == 0 && b.second == 0) {
			return false;
		}
		if (cross(a, b) == 0 && dot(a, b) >= 0)return ap.second < bp.second;
		int anum = deg(a);
		int bnum = deg(b);
		if (anum != bnum)return (anum < bnum);
		while (anum != 1) {
			swap(a.first, a.second);
			a.first *= -1;
			swap(b.first, b.second);
			b.first *= -1;
			anum = deg(a);
			bnum = deg(b);
		}
		LL a2 = a.first * a.first + a.second * a.second;
		LL b2 = b.first * b.first + b.second * b.second;
		LL ax2 = a.first * a.first;
		LL bx2 = b.first * b.first;
		bool res = (ax2 * b2 > bx2 * a2);
		return res;
	};
	sort(P.begin(), P.end(), [&](pair<PLL, int> a, pair<PLL, int> b) {
		return comp(a, b);
	});
	for (int n = 0; n < P.size(); n++)
	{
		points[n] = P[n].first;
	}
}

void solve() {
	vector<PLL> points0;
	for (int n = 0; n < N; n++)
	{
		points0.push_back(PLL(X[n], Y[n]));
	}
	N = points0.size();
	argsort(points0);
	V<PLL> sum(N);
	//for (int i = 0; i < N; i++)
	//{
	//	cout << atan2l(points0[i].second, points0[i].first) << "\n";
	//}
	sum[0] = points0[0];
	for (int n = 1; n < N; n++)
	{
		sum[n].first = sum[n - 1].first + points0[n].first;
		sum[n].second = sum[n - 1].second + points0[n].second;
	}
	LL ans = 0;
	//for (int s = 0; s < N; s++)
	//{
	//	//[s,e] \subset [0,N-1]
	//	for (int e = s; e < N; e++)
	//	{
	//		LL x = sum[e].first;
	//		LL y = sum[e].second;
	//		if (s > 0) {
	//			x -= sum[s - 1].first;
	//			y -= sum[s - 1].second;
	//		}
	//		ans = max(ans, x * x + y * y);
	//	}
	//	//[s,N-1]+[0,e]
	//	for (int e = 0; e < s; e++)
	//	{
	//		LL x = sum.back().first;
	//		LL y = sum.back().second;
	//		if (s > 0) {
	//			x -= sum[s - 1].first;
	//			y -= sum[s - 1].second;
	//		}
	//		x += sum[e].first;
	//		y += sum[e].second;
	//		ans = max(ans, x * x + y * y);
	//	}
	//}
	auto dot = [](PLL a, PLL b) {
		return a.first * b.first + a.second * b.second;
	};
	auto cross = [](PLL a, PLL b) {
		return a.first * b.second - a.second * b.first;
	};
	for (int cr = 0; cr < N; cr++)
	{
		PLL crv = points0[cr];
		for (int time = 0; time < 4; time++) {
			LL px = 0;
			LL py = 0;
			LL qx = 0;
			LL qy = 0;
			LL rx = 0;
			LL ry = 0;
			for (int i = 0; i < N; i++)
			{
				LL d = dot(crv, points0[i]);
				if (d < 0)continue;
				if (d > 0) {
					px += points0[i].first;
					py += points0[i].second;
					continue;
				}
				LL cro = cross(crv, points0[i]);
				if (cro > 0) {
					qx += points0[i].first;
					qy += points0[i].second;
				}
				if (cro < 0) {
					rx += points0[i].first;
					ry += points0[i].second;
				}
			}
			for (int code = 0; code < 4; code++)
			{
				LL x = px;
				LL y = py;
				if (code & 1) {
					x += qx;
					y += qy;
				}
				if (code & 2) {
					x += rx;
					y += ry;
				}
				ans = max(ans, x * x + y * y);
			}
			swap(crv.first, crv.second);
			crv.first *= -1;
		}
	}
	cout << setprecision(12) << sqrtl(ans) << "\n";
	return;
}