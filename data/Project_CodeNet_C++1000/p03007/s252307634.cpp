#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    deque<int> dq(v.begin(), v.end());
    vector<pair<int, int>> res;
    while (dq.size() > 2) {
        int n1 = dq.front();
        int n2 = dq.back();
        dq.pop_front();
        dq.pop_back();
        int next1 = n1 - n2;
        int next2 = n2 - n1;
        if (max(abs(next1 - dq.front()), abs(next1 - dq.back())) < max(abs(next2 - dq.front()), abs(next2 - dq.back()))) {
            dq.push_back(next2);
            res.push_back(make_pair(n2, n1));
        } else {
            dq.push_front(next1);
            res.push_back(make_pair(n1, n2));
        }
    }
    cout << dq.back() - dq.front() << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
    cout << dq.back() << " " << dq.front() << endl;
}
