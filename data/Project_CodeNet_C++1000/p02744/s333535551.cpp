#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> cur;
    vector<string> nxt;
    cur.push_back("a");

    for (int i = 1; i < n; ++i) {
        nxt.clear();
        for (auto& s : cur) {
            char mx = 'a';
            for (auto c : s) {
                mx = max(mx, c);
            }

            for (char ch = 'a'; ch <= mx + 1; ++ch) {
                string t = s;
                t += ch;
                nxt.push_back(t);
            }
        }
        swap(cur, nxt);
    }

    for (auto s : cur) {
        cout << s << '\n';
    }

    return 0;
}