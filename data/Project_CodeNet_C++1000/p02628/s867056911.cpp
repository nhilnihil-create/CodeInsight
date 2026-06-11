#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int N, K; cin >> N >> K;
    vector<int> nums;
    int p;
    for (int i = 0 ; i < N; ++i) {
        cin >> p;
        nums.push_back(p);
    }

    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < K; ++i) {
        res += nums[i];
    }    
	cout << res << endl;
}