#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

long LIS(vector<long> nums){
	long dp[100005];
	fill(dp, dp + nums.size(), INT_MAX);
	for (int i=0; i<nums.size(); ++i) {
		*lower_bound(dp, dp+nums.size(), nums[i]) = nums[i];
	}
	return lower_bound(dp, dp + nums.size(), INT_MAX) - dp;
}

int main(){
	long n;
	vector<long> nums;
	cin >> n;
	for(int i = 0; i < n; i++){
		long tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	cout << LIS(nums) << endl;
}