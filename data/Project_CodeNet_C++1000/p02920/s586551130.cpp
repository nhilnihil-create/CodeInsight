//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <time.h>
#include <stdio.h>

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
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
template<typename T>
void vdeb(std::vector<T> &da) {
	for (int i = 0;i < da.size();i++) {
		if (i == da.size() - 1) std::cout << da[i] << std::endl;
		else std::cout << da[i] << ' ';
	}
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
	for (int i = 0;i < da.size();i++) vdeb(da[i]);
	std::cout << std::endl;
}

using namespace std;

int main(){
	int n;cin >> n;
	vector<int> da(1 << n);
	rip(i,1 << n,0) cin >> da[i];
	sort(all(da));
	reverse(all(da));
	int now = 1;
	vector<bool> used(1 << n,false);
	used[0] = true;
	bool ju = true;
	rip(i,n,0){
		int po = 0, lo = 1, co = 0;
		vector<bool> permu = used;
		while(lo < (1 << n) && co < now && po < (1 << n)){
			//printf("%d %d %d\n",po,lo,co);
			//vdeb(used);
			if(!permu[po]) po++;
			else if(permu[lo] || da[lo] >= da[po]) lo++;
			else{
				used[lo] = true;
				co++;
				po++;
				lo++;
			}
		}
		if(co == now){
			now *= 2;
		}
		else{
			ju = false;
			break;
		}
	}
	printf((ju)? "Yes\n":"No\n");
}