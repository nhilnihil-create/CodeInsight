#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int64_t K;
    cin >> K;

    queue<int64_t> q;
    rep(i, 9) {
        q.push(i+1);
    }

    int64_t n = 0;
    rep(i, K) {
        n = q.front();
        q.pop();
        auto mod = n % 10;
        if(mod != 0) {
            q.push(n*10 + mod - 1);
        }
        q.push(n*10+mod);
        if(mod !=9) {
            q.push(n*10+mod + 1);
        }
    }
    cout << n << endl;

    return 0;
}
