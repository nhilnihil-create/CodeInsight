#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> votes;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        votes.push_back(a);
        sum += a;
    }
    int j = 0;
    double cutoff = sum / (4*m);
    for (int i = 0; i < n; i++) {
        if (votes[i] >= cutoff) j++;
    }
    if (j >= m) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
