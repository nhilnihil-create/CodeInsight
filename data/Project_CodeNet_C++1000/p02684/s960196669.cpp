#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#define N 10
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    long long k;
    cin >> n >> k;
    int a[n];
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i]--;
    }

    int memo[n];
    int root[n];
    memset(memo, -1, sizeof(memo));

    int now = 0;
    int c = 0;
    while (true) {
        root[c] = now;
        if (k - c == 0) {
            cout << now + 1 << endl;
            return 0;
        }
        if (memo[now] >= 0) {
            c -= memo[now];
            k -= memo[now];
            break;
        } else {
            memo[now] = c;
            c ++;
            now = a[now];
        }
    }

    int res = k % c;
    cout << root[memo[now] + res] + 1 << endl;
    return 0;
}