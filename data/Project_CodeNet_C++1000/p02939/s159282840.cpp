#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int ret = 0;
    string prev, now;
    for (int i = 0; i < s.size(); i++) {
        now += s[i];
        if (prev != now)ret++, prev = now, now.clear();
    }

    cout << ret << endl;
    return 0;
}