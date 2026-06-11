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
#define ABS(a) ((a)>0?(a):(-(a)))
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

    ll t1 = gi();
    ll t2 = gi();

    ll a1 = gli();
    ll a2 = gli();
    ll b1 = gli();
    ll b2 = gli();

    ll at = a1*t1+a2*t2;
    ll bt = b1*t1+b2*t2;
    if (at == bt) {
        printf("infinity\n");
        return 0;
    }

    ll at1 = a1*t1;
    ll bt1 = b1*t1;
    if ((at1 > bt1 && at > bt) || (at1 < bt1 && at < bt)) {
        printf("0\n");
        return 0;
    }

    ll fd = ABS(at - bt);
    ll fd1 = ABS(at1 - bt1);
    if (fd1%fd == 0) {
        cout << 2*fd1/fd << endl;
    } else {
        cout << 1+2*(fd1/fd) << endl;
    }

    return 0;
}
