#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
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

    bool unite(int from, int to) {
        int rx = root(from);
        int ry = root(to);
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
        return (base * modpow(base, pow - 1, mod)) % mod;
    }
}

long long int moddiv(long long int X, long long int Y, long long int mod) {
    auto fermatDiv = modpow(Y, mod - 2, mod);

    return (X * fermatDiv) % mod;
}

long long modCombination(long long left, long long right, long long int mod) {
    long long answer = 1;
    if (left > right) {
        for (long long i = 0; i < right; i++) {
            answer = (answer * (left - i)) % mod;
            answer = moddiv(answer, (i + 1), mod);
        }
    }
    return answer;
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

long long gcd(long long a, long long b) {
    if (b > a) {
        long long temp = b;
        b = a;
        a = temp;
    }
    //cout << "a:" << a << "b:" << b << endl;
    long long c = a % b;
    if (c == 0) {
        return b;
    }
    else {
        return gcd(b, c);
    }
}




int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> p(A), q(B), r(C);
    for (int i = 0; i < A; i++) {
        int temp;
        cin >> temp;
        p[i] = temp;
    }

    for (int i = 0; i < B; i++) {
        int temp;
        cin >> temp;
        q[i] = temp;
    }

    for (int i = 0; i < C; i++) {
        int temp;
        cin >> temp;
        r[i] = temp;
    }
    
    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    vector<int> eats(X + Y);
    for (int i = 0; i < X; i++) {
        eats[i] = p[i];
    }

    for (int i = 0; i < Y; i++) {
        eats[X + i] = q[i];
    }

    sort(eats.begin(), eats.end());

    for (int i = 0; i < min(C, X+Y); i++) {
        if (eats[i] <= r[i]) {
            eats[i] = r[i];
        }
        else {
            break;
        }
    }

    long long total = 0;
    for (auto e : eats) {
        total += e;
    }

    cout << total << endl;
    return 0;
}