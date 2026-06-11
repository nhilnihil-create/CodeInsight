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

long long int d_[5100];

int main(){
	long long int k, q;
	cin >> k >> q;
	for(int i = 0; i < k; i++){
		cin >> d_[i];
	}
	for(int loop = 0; loop < q; loop++){
		long long int n, x, m;
		cin >> n >> x >> m;
		long long int d[5100];
		long long int S = 0, S0 = 0, S1 = 0;
		for(int i = 0; i < k; i++){
			d[i] = d_[i] % m;
			S += d[i];
			if(d[i] == 0){
				S0 += 1;
			}
			// cout << d[i] << " ";
		}
		// cout << S << endl;
		n -= 1;
		long long int num = n / k, rem = n % k;
		long long int c1 = S / m, c2 = S % m;
		S = c2 * num % m + x % m;
		for(int i = 0; i < rem; i++){
			S += d[i];
			if(d[i] == 0){
				S1 += 1;
			}
		}
		// cout << S0 << " " << S1 << endl;
		cout << n - (c1 * num + c2 * num / m + S / m + S0 * num + S1) << endl;
	}
	return 0;
}