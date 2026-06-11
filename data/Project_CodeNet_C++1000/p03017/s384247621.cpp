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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    --A;
    --B;
    --C;
    --D;

    string S;
    cin >> S;

    for (size_t i = A; i < max(C, D); i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    
    if (D < C) {
        for (size_t i = B; i <= D; i++) {
            if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}
