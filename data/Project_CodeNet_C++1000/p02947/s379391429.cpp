#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;
void change(string& s) {
    vector<Int> v(26, 0);
    for (Int i = 0; i < (Int)s.length(); ++i) {
        v[s[i] - 'a']++;
    }
    s = "";
    for (Int i = 0; i < 26; ++i) {
        for (Int j = 0; j < v[i]; ++j) {
            s += ('a' + i);
        }
    }
    return;
}

int main(void) {
    Int n;
    cin >> n;
    vector<string> s(n);
    for (Int i = 0; i < n; ++i) {
        cin >> s[i];
        change(s[i]);
    }
    sort(s.begin(), s.end());

    Int result = 0;
    Int start = 0;
    Int end = 0;
    for (Int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            end++;
        } else {
            result += ((end - start) * (end - start + 1) / 2);
            start = i;
            end = i;
        }
    }
    result += ((end - start) * (end - start + 1) / 2);
    cout << result << endl;
    return 0;
}
