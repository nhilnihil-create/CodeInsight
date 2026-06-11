#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool comp(const pair<int, int> x, const pair<int, int> y) {
    return x.second > y.second;
}

int main(void) {
    int n;
    cin >> n;

    // (number, count)
    // number: 1 to n
    // count: count the number appears in A_i
    map<int, int> as;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = as.find(x);
        if (it == as.end()) {
            as[x] = 1;
        } else {
            as[x] = as.at(x) + 1;
        }
    }

    // sort as
    vector<pair<int, int>> bs;
    for (auto p : as) {
        bs.push_back(p);
    }

    sort(bs.begin(), bs.end(), comp);

    // ds[0] means the size of numbers which appears once in A_i.
    // ds[1] means ...                               twice in A_i.
    // ...
    vector<int> ds(n, 0);
    for (auto p : as) {
        ds[p.second-1]++;
    }

    // cout << "[ds]" << endl;
    // for (size_t i = 0; i < ds.size(); i++) {
    //     cout << i+1 << ":" << ds[i] << endl;
    // }
    // cout << endl;

    // calculate f(x) (see answer pdf)
    vector<int> fs(n);
    int m = bs.size(); // how many distinct numbers are in A_i
    int g = m;
    fs[0] = g / 1; // f(1)
    int acc = ds[0];
    for (int i = 1; i < n; i++) {
        g += (m - acc);
        fs[i] = g / (i+1);
        acc += ds[i];
    }

    // cout << "[fs]" << endl;
    // for (size_t i = 0; i < fs.size(); i++) {
    //     cout << i+1 << ":" << fs[i] << endl;
    // }
    // cout << endl;

    for (int k = 1; k <= n; k++) {
        int s = 0, e = n-1, mid, prev = -1;
        while (e - s >= 0) {
            mid = (s + e) / 2;
            if (fs[mid] >= k) {
                s = mid+1;
                prev = mid;
            } else {
                e = mid-1;
            }
        }
        if (prev < 0) {
            cout << 0 << endl;
        } else {
            cout << prev+1 << endl;
        }
    }

    return 0;
}
