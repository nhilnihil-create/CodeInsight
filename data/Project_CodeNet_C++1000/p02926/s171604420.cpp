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

typedef std::complex<double> V;

template<>
inline bool chmax(V &a, V b){
	if(norm(a) < norm(b)){
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main(){
	int n; cin >> n;
	vector<V> da(n);
	rip(i,n,0){
		int x,y; cin >> x >> y;
		da[i].real(x); da[i].imag(y);
	}
	sort(da.begin(), da.end(), [](const V &x, const V &y){return arg(x) < arg(y);});
	vector<V> daa = da;
	// vdeb(da);
	// cout << arg(da[0]) MM arg(da[1]) << endl;
	rip(i,n,0) daa.push_back(da[i]);
	V ans;
	rip(i,n,0){
		V now;
		rip(j,n,0){
			now += daa[(i+j)%n];
			chmax(ans, now);
		}
	}
	printf("%.10lf\n", sqrt((double)norm(ans)));
}