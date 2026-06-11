#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
template<class T> using hset = unordered_set<T>;
template<class Key, class T> using hmap = unordered_map<Key, T>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool isOutOfBounds(int y, int x, int h, int w) {
    return y < 0 || y >= h || x < 0 || x >= w;
}

int main() {
    vi prime = {2};
    for (int i=3; i<=123456*3; i++) {
        REP(j, prime.size()) {
            if (i % prime[j] == 0) break;
            if (j == prime.size() - 1) prime.push_back(i);
        }
    }

    int n;
    while (cin >> n) {
        if (n == 0) break;

        int i0 = 0;
        while (prime[i0] <= n) i0++;
        int i = 1;
        while (prime[i0+i] <= 2*n) i++;

        cout << i << endl;
    }

    return 0;
}