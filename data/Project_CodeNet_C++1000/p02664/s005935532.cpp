#include <cstring>
#include <cstdlib>
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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?(-(a)):(a))
#define CS while(cases())
#define I(n) int n = gi()
#define II(n) n = gi()
#define L(n) ll n = gli()
#define LL(n) n = gli()
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i < n; i++)
#define Fi(n, a) for (int i = 0; i < n; i++) a[i] = gi()
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

template<class T>
T gcd(T a, T b) {
    return (b == 0 ? a : gcd(b, a%b));
}

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

int cases() {
    static int t = gi();
    return t--;
}

#define MD 1000000007
char a[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 0; i < n; i++)
        if (a[i] == '?')
            a[i] = 'D';
    cout << a << endl;

    return 0;
}
