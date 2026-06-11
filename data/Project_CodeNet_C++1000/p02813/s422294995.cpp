#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int kai(int n) {
	int w = 1;
	for(int i=1;i<=n;i++){
		w = w * i;
	}
	return w;
}

int main(){
	int n;
	int cnt = 0;
	int psize = 0, qsize = 0;
	cin >> n;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; i++) {
		cin >> p.at(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> q.at(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p.at(i) > p.at(j))cnt++;
		}
		psize += cnt * kai(n - i - 1);
		cnt = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (q.at(i) > q.at(j))cnt++;
		}
		qsize += cnt * kai(n - i - 1);
		cnt = 0;
	}
	
	cout << abs(psize - qsize) << endl;
	return 0;
}
