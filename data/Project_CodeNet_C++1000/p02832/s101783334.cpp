#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(auto i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int safe = 0;
    int find = 1;
    for(auto &x: nums) {
        if(x == find){
            safe++;
            find++;
        }
    }
    if(safe){
        cout << n-safe << endl;
    }else{
        cout << -1 << endl;
    }
}