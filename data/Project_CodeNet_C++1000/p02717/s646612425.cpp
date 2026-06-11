#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    swap(nums[0], nums[1]);
    swap(nums[0], nums[2]);
    cout << nums[0] << ' ' << nums[1] << ' ' << nums[2] << endl;
    return 0;
}
