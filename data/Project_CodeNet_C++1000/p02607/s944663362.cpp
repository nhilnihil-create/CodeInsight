#include <iostream>
#include <vector>

using namespace std;

auto solve(int n, vector<int> a) {
    auto cnt = 0;
    for (int i = 0; i < n; i ++) {
        if ((i+1) % 2 == 1 && a[i] % 2 == 1) {
            cnt ++;
        }
    }

    return cnt;
}

int main() {
    int n;
    vector<int> a;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        a.emplace_back(t);
    }
    cout << solve(n, a) << endl;
    return 0;
}