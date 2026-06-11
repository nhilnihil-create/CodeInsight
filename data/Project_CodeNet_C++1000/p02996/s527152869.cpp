#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = make_pair(b, a);
    }
    sort(tasks.begin(), tasks.end());
    int sum_time = 0;
    string ans = "Yes";
    for (auto p: tasks) {
        sum_time += p.second;
        if (sum_time > p.first) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}