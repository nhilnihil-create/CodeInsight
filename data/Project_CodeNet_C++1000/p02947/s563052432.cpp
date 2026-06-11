#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string target;
    vector<string> targets;

    for (int i = 0; i < n; ++i) {
        cin >> target;
        sort(target.begin(), target.end());
        targets.push_back(target);
    }

    sort(targets.begin(), targets.end());
    long long sum_count = 0;
    long long count = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            sum_count += count * (count - 1) / 2;
            break;
        }
        if (targets[i] == targets[i - 1]) {
            ++count;
            continue;
        }
        sum_count += count * (count - 1) / 2;
        count = 1;
    }

    cout << sum_count << endl;

    return 0;
}