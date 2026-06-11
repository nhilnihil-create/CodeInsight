#include <bits/stdc++.h>
using namespace std;

float mix(float x = 0, float y = 0){
    float res = (x + y) / 2;

    return res;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n = 0;
    cin>>n;
    vector<float> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }


    while(nums.size() >= 2){
        sort(nums.begin(), nums.end());
        float first = nums[0];
        float last = nums[1];

        nums.erase(nums.begin() + 0, nums.begin() + 2);
        nums.push_back(mix(first, last));
    }

    cout<<nums[0];



    return 0;
}
