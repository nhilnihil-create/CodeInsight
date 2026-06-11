#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int n;

string s;

vector<int> a;

int main() {
    cin >> n >> s;

    bool no1 = true;
    for (int i = 1; i < n; i++) {
        int d = abs(s[i] - s[i-1]);
        a.PB(d);

        if (d == 1) {
            no1 = false;
        }
    }

    //PR0(a, n-1);

    if (no1) {
        for (auto& e : a) {
            e /= 2;
        }
    }

    int parity = 0;

    FORN(i, n-1) {
        if (((n-2-i) & i) == 0) {
            parity += a[i];
        }
    }

    if (parity % 2 == 0) {
        cout << 0 << "\n";
    }
    else if (no1) {
        cout << 2 << "\n";
    }
    else {
        cout << 1 << "\n";
    }
}
