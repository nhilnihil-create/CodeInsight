#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, l;
    cin >> N;
    deque<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        cin >> x >> l;
        A.emplace_back(make_pair(x - l, x + l));
    }

    sort(A.begin(), A.end(), 
        [](const auto &a, const auto &b) {return a.second < b.second;});

    int c = 0;
    int r = -1000000001;
    for (pair<int ,int> p : A) {
        if (p.first >= r) {
            c++;
            r = p.second;
        }
    }
    cout << c << endl;
}
