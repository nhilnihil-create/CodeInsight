#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){
	int M;
	cin >> M;
	long long int ans = -1, S = 0;
	for(int i = 0; i < M; i++){
		long long int d, c;
		cin >> d >> c;
		ans += c;
		S += d * c;
	}
	long long int cnt = 0;
	for(int i = 0; i < 100000; i++){
		cnt = (S + cnt) / 10;
	}
	cout << ans + cnt << endl;
	return 0;
}
