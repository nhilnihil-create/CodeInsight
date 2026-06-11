#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s.push_back('R');
    vector<int> res(n, 0);
    int l = 0, r = 0, state = 0;
    int index1 = 0, index2 = 0;
    for (int i = 0; i <= n; i++) {
        if (state == 0) {
            if (s[i] == 'R') {
                r++;
            } else {
                l++;
                index2 = i;
                state = 1;
            }
        } else {
            if (s[i] == 'R') {
                // merge result
                res[index2] += (l + 1) / 2 + r / 2;
                res[index2 - 1] += (r + 1) / 2 + l / 2;

                r = 1;
                l = 0;
                state = 0;
                index1 = i;
            } else {
                l++;
            }
        }
    }
    for (auto node : res)
        cout << node << " ";
    cout << endl;
}
