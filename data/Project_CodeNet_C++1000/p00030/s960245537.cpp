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

int n, s, res = 0;

void dfs(int num, int i, int sum){
	if(sum > s || 10 - i < n - num) return ;
	if(num == n){
		if(sum == s){
			res++;
			return ;
		} else {
			return ;
		}
	}
	dfs(num, i+1, sum);
	dfs(num+1, i+1, sum+i);

	return ;
}


int main(void){
	while(cin >> n >> s){
		if(n == 0 && s == 0) break;
		dfs(0, 0, 0);
		cout << res << endl;
		res = 0;
	}

	return 0;
}