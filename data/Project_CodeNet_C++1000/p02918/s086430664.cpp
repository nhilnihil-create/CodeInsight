#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;

int getResult(vector<int> nums){
    int n = nums.size();
    int maxx1 = nums[0];
    int maxx2 = nums[n-1];
    int res1 = 0,res2 = 0;
    for(int i = 1 ; i < n ; i ++){
        if(maxx1 < nums[i]){
            res1 ++;
        }
        maxx1 = min(maxx1,nums[i]);
    }
    for(int i = n-2; i >= 0 ; i --){
        if(maxx2 < nums[i]){
            res2 ++;
        }
        maxx2 = min(maxx2,nums[i]);
    }
    return min(res1,res2);
}

signed main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int res = 0;
    for(int i = 1 ; i < s.size(); i ++)
        if(s[i] == s[i-1]){
            res ++;
        }
    res = min(res+2*k,n-1);
    cout<<res<<endl;
}
