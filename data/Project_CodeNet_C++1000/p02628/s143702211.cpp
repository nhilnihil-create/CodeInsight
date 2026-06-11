#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, N;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i] ;
    }
    sort(nums.begin(), nums.end());
    int res = 0 ;
    for (int i = 0; i < K; i++) {
        res += nums[i];
    }
    cout << res << endl;
    return 0;
}