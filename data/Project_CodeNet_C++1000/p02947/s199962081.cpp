#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <string>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> sv(n);
    for (auto &e : sv) cin >> e;

    constexpr size_t alphabet = 'z' - 'a' + 1;

    auto count = [](const string &s) {
        array<int, alphabet> counter = { 0 };
        for (auto c : s) {
            ++counter[c - 'a'];
        }
        return counter;
    };

    int64_t ans = 0;

    map<array<int, alphabet>, int> anagram;
    for (auto &s : sv) {
        ++anagram[count(s)];
    }

    for (auto &s : sv) {
        ans += --anagram[count(s)];
    }

    cout << ans << endl;
}

