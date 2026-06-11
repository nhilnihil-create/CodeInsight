#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> data(1<<n);
    for (int i = 0; i < (1<<n); i++) cin >> data[i];
    sort(data.begin(), data.end());
  
    vector<int> check;
    check.push_back(*data.rbegin());
    multiset<int> mst;
    for (int i = 0; i < (1<<n) - 1; i++) mst.insert(data[i]);
    for (int i = 0; i < n; i++) {
        vector<int> add;
        for (int j = 0; j < (1<<i); j++) {
            int ch = check[j];
            auto iter = mst.lower_bound(ch);
            if (iter == mst.begin()) {
                cout << "No" << endl;
                return 0;
            }
            iter = prev(iter);
            add.push_back(*iter);
            mst.erase(iter);
        }
        for (int j = 0; j < (1<<i); j++) check.push_back(add[j]);
        sort(check.begin(), check.end(), greater<int>());
    }
    cout << "Yes" << endl;
    return 0;
}