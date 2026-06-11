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

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            parent[ry] += parent[rx];
            parent[rx] = ry;

            return true;
        }
        else {
            return false;
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

bool IsPrime(long long N) {
    if (N == 1) {
        return false;
    }
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }

    return true;
}

bool IsPE(long long z) {
    for (long long i = 2; i <= z; i++) {
        if (z % i == 0 && IsPrime(i)) {
            long long test = i;
            while (test < z) {
                test *= i;
            }
            if (test == z) {
                return true;
            }
        }
    }

    return false;
}

long long  solve(long long N) {
    long long answer = 0;
    long long divider = 2;
    
    while (N >= divider) {
        if (N % divider == 0 && IsPE(divider)) {
            //cout << divider << endl;
            answer++;
            N /= divider;
        }
        
        divider++;
    }

    return answer;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({ a, ex });
    }

    // 最後に残った数について
    if (N != 1) res.push_back({ N, 1 });
    return res;
}


bool IsOK(long long a, long long b) {
    return ((b - a / 2) % a) == 0;
}

long long euclid(long long a, long long b) {
    if (a > b) {
        long long temp = b;
        b = a;
        a = temp;
    }
    if (b % a == 0) {
        return a;
    }
    else {
        return euclid(a, b - a);
    }
}

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    long long maxA = -1;
    for (long long i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        a[i] = temp;
        if (temp > maxA) {
            maxA = temp;
        }
    }

    long long minimumHalf = maxA * 0.5;
    bool isFound = false;

    while (!isFound && minimumHalf <= M) {
        isFound = true;
        for (auto k : a) {
            isFound = IsOK(k, minimumHalf);
            if (!isFound) {
                minimumHalf += maxA;
                break;
            }
        }
    }

    if (isFound) {
        long long l = 1;
        for (auto k : a) {
            l = k * l / euclid(l, k);
        }

        long long count = (M - minimumHalf) / l + 1;

        cout << count << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    
    return 0;
}