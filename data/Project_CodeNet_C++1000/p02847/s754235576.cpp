#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int ans = 1;
    string str;
    cin >> str;
    vector<string> weeks = {"SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
    rep(i, 7) {
        if(weeks.at(i) == str) ans += i;
    }
    cout << ans << endl;
}