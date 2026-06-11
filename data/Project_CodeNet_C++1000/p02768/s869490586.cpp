#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stdlib.h>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long int MOD = 1000000000 + 7;

struct UnionFind {
    vector<int> parent;

    UnionFind(int N) : parent(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
        }
    }

    int root(int i) {
        if (parent[i] < 0) {
            return i;
        }
        return (parent[i] = root(parent[i]));
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            parent[ry] += parent[rx];
            parent[rx] = ry;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int treeSize(int x) {
        

        return -parent[root(x)];
    }
};

long long int modpow(long long int base, long long int pow, long long int mod) {
    if (pow == 1) {
        return base;
    }
    else if (pow == 0) {
        return 1;
    }

    if (pow % 2 == 0) {
        auto temp = modpow(base, pow / 2, mod);
        return (temp * temp) % mod;
    }
    else {
        return base * modpow(base, pow - 1, mod) % mod;
    }
}

long long int moddiv(long long int X, long long int Y, long long int mod) {
    auto fermatDiv = modpow(Y, mod - 2, mod);

    return (X * fermatDiv) % mod;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    long long int answer = modpow(2, n, MOD) - 1;


    long long int aComb = 1;
    for (long long int i = 0; i < a; i++) {
        aComb *= moddiv(n - i, i + 1, MOD);
        aComb %= MOD;
    }


    long long int bComb = 1;
    for (long long int i = 0; i < b; i++) {
        bComb *= moddiv(n - i, i + 1, MOD);
        bComb %= MOD;
    }



    answer += MOD - aComb;
    answer += MOD - bComb;

    cout << answer % MOD << endl;

    
    return 0;
}