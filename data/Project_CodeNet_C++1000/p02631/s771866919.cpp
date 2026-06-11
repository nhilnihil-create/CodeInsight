#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        sum = sum ^ nums[i];
    }
    // cout << sum << endl;
    for (int i = 0; i < N; i++) {
        cout << (nums[i] ^ sum) << ' ';
    }
    return 0;

}