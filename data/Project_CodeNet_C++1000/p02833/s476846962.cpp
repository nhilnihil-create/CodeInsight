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
    uint64_t N;
    cin >> N;

    if(N % 2) {
        cout << 0 << endl;
        return 0;
    }

    uint64_t ret = 0;
    uint64_t diviser = 10;

    while(1) {
        uint64_t diff = N / diviser;
        ret += diff;
        if(diff==0)
            break;
        diviser *= 5;

    }
    cout << ret << endl;

    return 0;
}

