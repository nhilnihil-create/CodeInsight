#include <bits/stdc++.h>
using namespace std;

int main()

{
    vector<int> nums;
    int input; cin>>input;
    for(int i=0; i<input;i++){
        int n; cin>>n;
        nums.push_back(n);
    }
    double temp=0;
    for(int i=0; i<input;i++){
        temp+=pow(nums[i], -1);
    }
    double result = pow(temp, -1);
    cout<<result<<endl;
    return 0;
}