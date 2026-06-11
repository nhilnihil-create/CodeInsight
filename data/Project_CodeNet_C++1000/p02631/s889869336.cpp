#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> nums;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        nums.push_back(a);
    }
    vector<int> sols;
    a = 0;
    for (int i = 1; i < N; i++) {
        a ^= nums[i];
    }
    sols.push_back(a);
    for (int i = 0; i < N - 1; i++) {
        int b = nums[0] ^ nums[i+1];
        int c = sols[0] ^ b;
        sols.push_back(c);
    }
    for (int i = 0; i < N; i++) {
        cout << sols[i] << " ";
    }
}
