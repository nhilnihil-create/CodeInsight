/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    int total = accumulate(nums.begin(), nums.end(), 0);
    int mn = total;
    int left = 0;
    for(int num : nums) {
        left += num;
        int cur = abs(left - (total - left));
        mn = min(mn, cur);
    }
    cout << mn << endl;
    return 0;
    
}

