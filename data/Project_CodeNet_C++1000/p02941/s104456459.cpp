/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

const long long MAXN = 1e6 + 1;
const long long ZB = 1e18;
const long long MOD = 1e9 + 7;
using namespace std;

typedef pair<int, int> pii;


long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}

void fail() {
    cout << -1;
    exit(0);
}



#define ll long long

ll a[MAXN];
ll  b[MAXN];


int N(int i, int k) {
    if (i == k) return 1;
    return i + 1;
}
int P(int i, int k) {
    if (i == 1) return k;
    return i - 1;
}
main(){
    int n = readInt();
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        b[i] = readInt();
        if (b[i] < a[i]) fail();
        que.push(i);
    }

    ll ans = 0;

    while (que.size()) {
        int i = que.front(); que.pop();
        ll near = b[N(i, n)] + b[P(i, n)];
        ll u = (b[i] - a[i]) / near;
        if (u <= 0) continue;
        ans += u;
        b[i] -= near * u;
        que.push(P(i, n));
        que.push(N(i, n));
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) fail();
    }

    cout << ans << endl;

    return 0;
}

