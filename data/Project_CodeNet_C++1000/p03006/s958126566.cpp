#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    map<pair<int, int>, int> m;
    int M = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int p = v[i].first - v[j].first;
            int q = v[i].second - v[j].second;
            M = max(M, ++m[make_pair(p, q)]);
        }
    }
    cout << N-M << endl;
}