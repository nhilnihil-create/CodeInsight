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

void dfs(int n, char biggest, string s, const int N) {
    if (n == N) {
        cout << s << endl;
        return;
    }

    for (char c = 'a'; c <= biggest + 1; c++) {
        dfs(n + 1, max(c, biggest), s + c, N);
    }
}

int main(void) {
    int N;
    cin >> N;

    dfs(1, 'a', "a", N);

    return 0;
}
