#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    
    for(auto &val : nums) cin >> val;
    reverse(nums.begin(), nums.end());
    
    for(int i = 0; i < n-1; i++){
        cout << nums[i] << " ";
    }
    cout << nums[n-1] << endl;
    
    return 0;
}