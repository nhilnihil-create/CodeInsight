#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){

	int a, b, c;
	cin >> a >> b >> c;

	int ans = 0;

	for(int i = a; i <= b; i++){
		if(c % i == 0){
			ans += 1;
		}
	}

	cout << ans << endl;

	return 0;
}
