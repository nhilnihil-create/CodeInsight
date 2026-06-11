#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    int A, B;
    cin >> A >> B;

    int ans = -1;
    for (int x = 0; x <= 2000; x++) {
        if (x * 8 / 100 == A && x * 10 / 100 == B) {
            ans = x;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
