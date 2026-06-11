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
#include <bitset>

using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<long long int, P> P2;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[2100][2100];

int main(){
	int N;
	cin >> N;
	vector<P> v;
	for(int i = 0; i < N; i++){
		P p;
		cin >> p.first;
		p.second = i;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i = 0; i < N; i++){
		P p = v[i];
		DP[i + 1][0] = DP[i][0] + p.first * (p.second - i);
		DP[0][i + 1] = DP[0][i] + p.first * (N - 1 - p.second - i);
		for(int j = 1; j < i + 1; j++){
			DP[j][i + 1 - j] = max(
				DP[j - 1][i + 1 - j] + p.first * (p.second - (j - 1)),
				DP[j][i - j] + p.first * (N - 1 - p.second - (i - j))
			);
		}
	}
	long long int ans = 0;
	for(int i = 0; i <= N; i++){
		ans = max(ans, DP[i][N - i]);
	}
	cout << ans << endl;
	return 0;
}
