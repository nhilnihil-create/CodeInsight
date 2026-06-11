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
#include <queue>
#include <algorithm>
using namespace std;

int max(int a, int b) {
    return (a>b)?a:b;
}

int main(int argc, char const *argv[])
{
    int K;
    cin >> K;

    vector<long long> memo(10);
    memo[0] = 0;
    if (K < 10) {
        cout << K << endl;
        return 0;
    }
    for(int i = 1; i < 10; i ++) {
        memo[i] = i;
    }

    long long ans;
    K -= 9;

    int now, mod;
    now = 1;

    while (1) {
        mod = memo[now] % 10;
        for (int i = max(mod-1,0); i<10 && i<=mod+1; i ++) {
            ans = memo[now] * 10 + i;
            memo.push_back(ans);
            K --;

            if (!K) {
                cout << ans << endl;
                return 0;
            }
        }
        now ++;
    }
    return 0;
}