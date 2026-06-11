// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include<unordered_map>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
void vdeb(std::vector<T> &da) {
	for (int i = 0;i < da.size();i++) {
		if (i == da.size() - 1) std::cout << da[i];
		else std::cout << da[i] << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
	for (int i = 0;i < da.size();i++) vdeb(da[i]);
	std::cout << std::endl;
}

using namespace std;


int main(){
	int n, k; cin >> n>> k;
	vector<ll> da(n+1);
	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+2, vector<ll>(n+1, LLONG_MAX/2)));
	rip(i,n,0) cin >> da[i+1];
	dp[0][0][0] = 0;
	rip(i,n+1,1){
		rip(j,k+1,0){
			rip(l, i, 0){
				dp[i][j+1][l] = dp[i-1][j][l];
				chmin(dp[i][j][i], dp[i-1][j][l] + max(da[i] - da[l], 0LL));
			}
		}
	}
	ll ans = LLONG_MAX/2;
	rip(i,k+1,0){
		rip(j,n+1,0){
			chmin(ans, dp[n][i][j]);
		}
	}
	// vdeb(dp);
	cout << ans << endl;
}