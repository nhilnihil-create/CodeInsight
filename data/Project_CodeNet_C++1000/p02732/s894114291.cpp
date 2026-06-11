#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<long long> a(n), nums(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nums[a[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += nums[i] * (nums[i] - 1) / 2;

    for (int i = 0; i < n; i++) {
        long long new_ans = ans - nums[a[i]] * (nums[a[i]] - 1) / 2 + (nums[a[i]] - 1) * (nums[a[i]] - 2) / 2;
        cout << new_ans << endl;
    }
    return 0;
}
