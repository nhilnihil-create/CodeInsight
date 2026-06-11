#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<int> l;

int main() {
    int n;
    cin >> n;
    l.resize(n);
    rep(i, n) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    long sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            vector<int>::iterator begin = l.begin() + j + 1;
            vector<int>::iterator end = l.end();
            int left = l[j] - l[i];
            int right = l[i] + l[j];
            // left < a[i] < right を満たすa[i]の個数は、
            // right未満のa[i]の個数 - left以下のa[i]の個数に等しい
            sum += lower_bound(begin, end, right) - upper_bound(begin, end, left);
        }
    }
    cout << sum << endl;
}