#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
using namespace std;

int jousu(int, int);
int jousu(int x, int y) {
	int z = 1;
	for (int i = 0; i < y; i++) {
		z *= x;
	}
	return z;
}
int kurai(int x, int y) {
	int z = (x%jousu(10,y)) / jousu(10, y-1);
	return z;
}
int keta(int x) {
	int z = x;
	int w = 0;
	while (z != 0) {
		z /= 10;
		w++;
	}
	return w;
}

int n, b = 0;;
string a;
bool c = false;
int main(){
	cin >> n;
	vector<pair<string, int>>list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i].first >> list[i].second;
	}
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (c) {
			b += list[i].second;
		}
		if (list[i].first == a) {
			c = true;
		}
	}
	cout << b << endl;
}