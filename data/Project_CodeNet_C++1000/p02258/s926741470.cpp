#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<long> nums;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	long del_max = nums[1] - nums[0];
	long minv = nums[0];
	for (int j = 1; j < n; ++j) {
		long delta = nums[j] - minv;
		if (delta > del_max) {
			del_max = delta;
		}
		if (minv > nums[j]) {
			minv = nums[j];
		}
	}
	cout << del_max << endl;	
}