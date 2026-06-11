#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_N (123456 * 2 + 1)

bool sieve[MAX_N];

int main() {
    sieve[0] = sieve[1] = true;
    FOR(i, 2, MAX_N) {
        if (sieve[i]) continue;
        for (int j = i + i; j <= MAX_N; j += i) {
            sieve[j] = true;
        }
    }

    int n;
    while (cin >> n, n) {
        int count = 0;
        FOR(i, n + 1, n * 2) {
            if (!sieve[i]) count++;
        }
        cout << count << endl;
    }
}