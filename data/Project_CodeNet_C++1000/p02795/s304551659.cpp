#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <algorithm>
#define PB push_back
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define PIE (3.14159265358979323846)
#define MOD 1000000007;
using namespace std;

void checkStream() {
    #ifndef _DEBUFG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // checkStream();

    int r {}, c {}, n {};
    cin >> r >> c >> n;

    int step1 {}, step2 {};
    int ttl {};
    for (int i {}; i < r && ttl < n; ++i) {
        ttl += c;
        ++step1;
    }

    ttl = 0;
    for (int i {}; i < c && ttl < n; ++i) {
        ttl += r;
        ++step2;
    }
    cout<<min(step1, step2)<<endl;
    return 0;
}
