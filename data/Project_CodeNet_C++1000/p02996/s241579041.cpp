#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else return a.first < b.first;
}

int main() {
    int N; cin >> N;
    vector<pair<int, int>> work(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        work.at(i) = make_pair(a, b);
    }
    sort(work.begin(), work.end(), cmp);
    int time = 0;
    for (int i = 0; i < N; i++) {
        time += work.at(i).first;
        if (time <= work.at(i).second) continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}