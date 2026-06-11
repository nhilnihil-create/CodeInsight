#include <bits/stdc++.h>
using namespace std;

int ans[510][510];

void f(vector<int> v, int lv) {
    if (v.size() == 1) return;
    vector<int> v1, v2;
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() / 2) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            ans[v1[i]][v2[j]] = lv;
            ans[v2[j]][v1[i]] = lv;
        }
    }
    f(v1,lv+1);
    f(v2,lv+1);
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    f(v,1);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << ans[i][j] << " \n"[j == n];
        }
    }
    return 0;
}
