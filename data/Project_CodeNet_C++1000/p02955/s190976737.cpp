//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;


bool check(int x, int k, int n, vector<int> &arr) {
    vector<int> reminders;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int rem = arr[i] % x;
        if (rem) {
            reminders.push_back(rem);
            sum += rem;
        }
    }
    sort(reminders.begin(), reminders.end());
    if (reminders.empty())
        return true;
    long long a = 0;
    for (int i = 0; i < (int)reminders.size(); ++i) {
        a += reminders[i];
        long long b = 1LL * ((int)reminders.size() - i - 1) * x - (sum - a);
        if (a == b && a <= k) {
            return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int sum = 0;
    for (int &x : arr) {
        cin >> x;
        sum += x;
    }

    int ans = 0;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
//            cout << i << '\n';
            if (check(i, k, n, arr))
                ans = max(ans, i);
            if (check(sum / i, k, n, arr))
                ans = max(ans, sum / i);
        }
    }

    cout << ans << '\n';

    return 0;
}