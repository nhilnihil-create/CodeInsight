#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec.at(i);
    sort(vec.begin(), vec.end());
    int center = (int)(vec.size() / 2);
    int ans = vec.at(center) - vec.at(center-1);
    cout << ans << endl;
    return 0;
}