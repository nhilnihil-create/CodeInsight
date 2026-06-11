#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>

#pragma warning( disable: 4996 )

using namespace std;

typedef long long ll;

#define INF 100000000
#define EPS 1e-9

#define MAX_N 1234570

bool prime[MAX_N];
int dp[MAX_N];

vector<int> ans_list;

int main(){

	prime[0] = prime[1] = true;

	for (int i = 1; i < MAX_N; i++){
		dp[i] = dp[i - 1];
		if (!prime[i]){
			dp[i]++;
			for (int j = 2; i * j < MAX_N; j++){
				prime[i*j] = true;
			}
		}
	}

	while (true){
		int n;
		cin >> n;
		if (n == 0)
			break;

		ans_list.push_back(dp[2*n] - dp[n]);

	}

	for (int i = 0; i < ans_list.size(); i++){
		cout << ans_list[i] << endl;
	}


	return 0;

}