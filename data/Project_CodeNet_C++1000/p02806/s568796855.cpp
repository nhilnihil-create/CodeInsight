#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> ms;
    for (int i=0; i<n; i++) {
        string s; int t;
        cin >> s >> t;
        ms.push_back(make_pair(s, t));
    }
    string x;
    cin >> x;
    bool is_sleep = false;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (is_sleep) {
            ans += ms[i].second;
            continue;
        }
        if (ms[i].first == x) is_sleep = true;
    }
    cout << ans << endl;
}