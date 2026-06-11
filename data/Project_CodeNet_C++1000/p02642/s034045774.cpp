#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }

    if (A.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> dp(A.rbegin()->first + 1, true);

    for (auto num : A) {
        int count = 2;
        while (count * num.first < dp.size()) {
            dp[count * num.first] = false;
            count++;
        }
    }

    int output = 0;
    for (auto num : A) {
        if (dp[num.first] && num.second == 1) {
            output++;
        }
    }

    cout << output << endl;

    return 0;
}
