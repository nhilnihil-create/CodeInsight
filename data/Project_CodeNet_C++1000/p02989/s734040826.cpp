#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    cout << nums[nums.size() / 2] - nums[nums.size() / 2 - 1] << "\n";
    return 0;
}
