#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    string S;
    cin >> S;

    char last = S[0];
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == last) {
            cout << "Bad" << endl;
            return 0;
        }
        last = S[i];
    }

    cout << "Good" << endl;
    return 0;
}
