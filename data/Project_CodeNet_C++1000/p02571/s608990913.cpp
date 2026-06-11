#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 111;
int main() {
    string a, b;
    cin >> a >> b;
    int aa = a.length(), bb = b.length();
    int maxcnt = 0;
    for (int i = 0; i + bb - 1 < aa; ++i) {
        int cnt = 0;
        for (int j = 0; j < bb; ++j) {
            if (a[i + j] == b[j]) ++cnt;
        }
        maxcnt = max(maxcnt, cnt);
    }
    printf("%d\n", bb - maxcnt);
    return 0;
}