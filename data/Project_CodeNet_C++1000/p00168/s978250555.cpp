#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <iterator>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
 
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())

typedef unsigned long long ull;
const int INF = (int)1e8;


int main(){
	int dp[31];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= 30; i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}

	int n;
	while(cin>>n,n){
		cout << (dp[n] + 3649) / 3650 << endl;
	}

	return 0;
}