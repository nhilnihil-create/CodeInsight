#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string s;
    cin >> s;

    int s_len = s.size();
    reverse(s.begin(), s.end());

    long long ans = 0;
    int x = 1;
    int sum = 0;
    vector<int> cnt(2019);
    for ( int i = 0; i < s_len; i++ ) {
        cnt.at(sum)++;
        sum += (s.at(i) - '0') * x;
        sum %= 2019;
        ans += cnt.at(sum);
        x = (10 * x) % 2019;
    }

    cout << ans << endl;
    return 0;
}
