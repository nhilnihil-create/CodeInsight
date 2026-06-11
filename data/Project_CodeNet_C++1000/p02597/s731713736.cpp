#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<char> nums(N);
    int wnum = 0;
    for (int i = 0; i < N; i++){
        cin >> nums[i];
        if (nums[i] == 'W') wnum++;
    }
    int res1 = 0;
    for (int i = 0; i < N - wnum; i++) {
        if (nums[i] == 'W') res1++;
    }
    cout << res1 << endl;
    
    return 0;
}