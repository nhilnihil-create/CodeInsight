#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a_max;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec.at(i);
    sort(vec.begin(), vec.end());
    a_max = vec.back();
    vector<bool> bl(a_max + 1, true);
    for (size_t i = 0; i < vec.size(); i++) {
        if (i != 0 && vec.at(i - 1) == vec.at(i)) {
            bl.at(vec.at(i)) = false;
        }
        if (bl.at(vec.at(i))) {
            for (int j = 2; j * vec.at(i) <= a_max; j++) {
                bl.at(vec.at(i) * j) = false;
            }
        }
    }
    int cnt = 0;
    for (auto &x : vec) {
        if (bl.at(x)) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
