#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>S;
        int l=0;
        S.insert(nums[0]);
        int ans=0;
        for (int i=1;i<nums.size();i++) {
            while ((*S.rbegin()-*S.begin())>limit && l<i) {
                S.erase(S.find(nums[l]));
                l++;
            }

            ans=max(ans, (int)S.size());
            S.insert(nums[i]);
        }
        return ans;
    }
};

int main() {
    long long x;
    long long ans=0;
    cin>>x;
    ans=x*(x-1)/2;
    cout<<ans<<endl;
    return 0;
}
