#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    //priority_queue<int, vector<int>, std::greater<int>> q;
    priority_queue<int> q;
    rep(i, N) {
        int A;
        cin >> A;
        q.push(A);
    }

    rep(i, M) {
        int X = q.top();
//        cout << X << " to " << X/2 << endl;
        q.pop();
        q.push(X/2);
    }
    uint64_t ret = 0;
    rep(i, N) {
        ret += q.top();
        q.pop();
    }
    cout << ret << endl;

    return 0;
}

