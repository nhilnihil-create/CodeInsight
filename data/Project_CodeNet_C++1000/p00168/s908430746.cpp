#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <queue>
#include <complex>
#include <climits>

typedef long long ll;

using namespace std;



int main(){
	int n;
	int dp[40];
	
	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for(int i=4; i<35; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}

	while(cin >> n){
		if(!n) break;
		cout << (dp[n] + 3649) / 3650  << endl;
	}


    return 0;
}