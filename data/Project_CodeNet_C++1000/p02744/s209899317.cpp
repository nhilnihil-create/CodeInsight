#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    int n;
    cin >> n;

    queue<string> q;
    q.push("a");

    while (!q.empty()) {
        auto s = q.front();
        q.pop();

        if (s.size() == n) {
            cout << s << endl;
        } else {
            map<char, int> mp;
            for (char c : s) mp[c]++;

            for (int i = 0; i <= mp.size(); i++) {
                string t = s;
                t.push_back('a' + i);
                q.push(t);
            }
        }
    }

    return 0;
}