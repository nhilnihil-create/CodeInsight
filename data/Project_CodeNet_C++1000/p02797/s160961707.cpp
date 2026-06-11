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
    int N, K, S;
    cin >> N >> K >> S;

    for (int i = 0; i < K; i++) {
        cout << S << ' ';
    }

    for (int i = 0; i < N - K; i++) {
        if (S == 1e9) {
            cout << 1 << ' ';
        } else {
            cout << S + 1 << ' ';
        }
    }

    cout << endl;
    return 0;
}
