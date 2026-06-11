#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;


vector<int>nums;
vector<int>oddnums;

vector<short>memo(1000001,-1);
vector<short>oddmemo(1000001,-1);

int getans(const int num,const int atime) {
	if (memo[num] != -1) {
		return memo[num];
	}
	else {
		if (num == 0)return memo[num] = 0;
		int ans = num;
		for (int i = 0; i <nums.size(); ++i) {
			int minusnum = nums[i];
			if (minusnum > num) {
				break;
			}
			else if (num / minusnum > 10) {
				continue;
			}
			ans = min(ans, getans(num - minusnum, atime + 1)+1);
		}

		return memo[num] = ans;
	}
}
int getoddans(const int num, const int atime) {
	if (oddmemo[num] != -1) {
		return oddmemo[num];
	}
	else {
		if (num == 0)return oddmemo[num] = 0;
		int ans = num;
		for (int i = 0; i < oddnums.size(); ++i) {
			int minusnum = oddnums[i];
			if (minusnum > num) {
				break;
			}
			else if (num / minusnum > 100) {
				continue;
			}
			ans = min(ans, getoddans(num - minusnum, atime + 1) + 1);
		}
		return oddmemo[num] = ans;
	}

}
int main() {
	for (int i = 1; i < 190; ++i) {
		nums.push_back(i*(i + 1)*(i + 2) / 6);
		if (((i*(i + 1)*(i + 2)) / 6) % 2) {

		
			oddnums.push_back((i*(i + 1)*(i + 2)) / 6);
		}
	}

	while (1) {
		int n; cin >> n;
		if (!n)break;
		int normalans = getans(n, 0);;
		int oddans = getoddans(n, 0);

		cout << normalans << " " << oddans << endl;
	}
	return 0;
}