#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    long long ans = 0;

    unordered_map<string, int> dict;
    for (size_t i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (dict[s] == 0) dict[s]++;
        else {
            ans += dict[s];
            dict[s]++;
        }
    }

    cout << ans << endl;
    return 0;
}
