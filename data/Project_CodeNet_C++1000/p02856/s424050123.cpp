#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = gi();
    ll s = 0;
    ll sd = 0;
    for (int i = 0; i < n; i++) {
        ll d = gi();
        ll c = gli();
        s += c*d;
        sd += c;
    }

    ll res = s/9 - (s%9 ? 0 : 1);
    res += sd-1;
    cout << res << endl;

    return 0;
}
