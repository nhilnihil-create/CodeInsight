#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int t = vec.at(i) + vec.at(j);
            int r = lower_bound(vec.begin(), vec.end(), t) - vec.begin();
            int l = i + 1;
            cnt += r - l;
        }        
    }
    cout << cnt << endl;
}
