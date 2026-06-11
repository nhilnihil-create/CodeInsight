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
using ll = long long;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

typedef priority_queue<int, vector<int>, greater<int>> priority_queue_asc;

int main() {
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    bool isReverse = false;

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            isReverse = !isReverse;
        } else if (t == 2) {
            int f;
            cin >> f;
            if ((f == 1 && !isReverse) || (f == 2 && isReverse)) {
                char c;
                cin >> c;
                S = c + S;
            } else if ((f == 2 && !isReverse) || (f == 1 && isReverse)) {
                char c;
                cin >> c;
                S.push_back(c);
            }
        }
    }

    if (isReverse) {
        reverse(S.begin(), S.end());
    }
    cout << S << endl;


    return 0;
}
