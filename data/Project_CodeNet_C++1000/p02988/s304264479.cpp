#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int count = 0;
    rep(i, n) cin >> vec.at(i);
    rep(i, n - 2) {
        int x = vec.at(i + 1);
        if (vec.at(i) < x && x < vec.at(i + 2)) count++;
        else if (vec.at(i) > x && x > vec.at(i + 2)) count++;
        else continue;
    }
    cout << count << endl;
    return 0;
}