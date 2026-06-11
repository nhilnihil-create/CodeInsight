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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int hapiness = 0;
    {
        // hapiness for R
        for (int i = 0; i < N - 1; i++) {
            if (S[i] == 'R' && S[i + 1] == 'R') {
                hapiness++;
            }
        }

        // hapiness for L
        for (int i = N - 1; i > 0; i--) {
            if (S[i] == 'L' && S[i - 1] == 'L') {
                hapiness++;
            }
        }
    }

    // printf("initial_hapiness: %d\n", hapiness);

    cout << min(N - 1, hapiness + 2 * K) << endl;

    return 0;
}
