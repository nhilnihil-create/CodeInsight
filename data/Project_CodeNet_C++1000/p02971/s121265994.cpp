#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    vector<int> copy(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        copy.at(i) = a.at(i);
    }
    sort(copy.begin(), copy.end());
    int mx = copy.at(N-1), mx2 = copy.at(N-2);
    for (int i = 0; i < N; i++) {
        if (a.at(i) == mx) cout << mx2 << endl;
        else cout << mx << endl;
    }
}