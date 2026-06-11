// Copyright [2020] <unknown>
#include <bits/stdc++.h>
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define dbg(x...) { cerr << "\033[32;1m" << #x << " -> "; err(x); }
void err() { cerr << "\033[39;0m" << endl; }
template<typename T, typename... A>
void err(T a, A... x) { cerr << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

#define sz(x) ((int)x.size())

typedef long long LL;

const int a[] = {
    1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51
};


int main(int argc, char const *argv[]) {
    // code
    int k;
    cin >> k;
    cout << a[k-1] << endl;
    return 0;
}
