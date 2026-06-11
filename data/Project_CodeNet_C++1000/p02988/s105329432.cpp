#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, p = 0, cnt = 0;
    vector<int> vec;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p;
        vec.push_back(p);
    }

    for (int i = 0; i < vec.size(); ++i) {
        if (i >= 1 && i < vec.size() - 1) {
            if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1])continue;
            if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1])continue;
            cnt++;
        }
    }

    cout << cnt << endl;

}