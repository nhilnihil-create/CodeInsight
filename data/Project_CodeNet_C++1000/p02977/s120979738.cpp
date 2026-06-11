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

int rs[200000];

int main() {
    int n = gi();
    for (int i = 0; i < 17; i++)
        if ((1 << i) == n) {
            printf("No\n");
            return 0;
        }

    int a = n, b = 1, c;
    while (a > 1) {
        a /= 2;
        b *= 2;
    }

    printf("Yes\n");
    switch(n%4) {
        case 1:
            for (int i = 2; i < n; i++)
                printf("%d %d\n", i, i+1);
            for (int i = n + 2; i < 2*n; i++)
                printf("%d %d\n", i, i+1);
            printf("1 2\n%d 3\n%d %d\n", n+1, n, n+2);
            break;
        case 3:
            for (int i = 1; i < 2*n; i++)
                printf("%d %d\n", i, i+1);
            break;
        case 0:
            rs[0] = b;
            rs[1] = n-b;
            c = 2;
            for (int i = 1; i < n; i++)
                if (i != b && i != n-b)
                    rs[c++] = i;
            for (int i = 0; i < n-1; i++)
                rs[n-1+i] = rs[i] + n;
            printf("%d %d\n%d %d\n", n, b, 2*n, n-b);
            for (int i = 1; i < 2*n-2; i++)
                printf("%d %d\n", rs[i-1], rs[i]);
            break;
        case 2:
            rs[0] = n-b;
            rs[1] = b;
            rs[2] = b+1;
            c = 3;
            for (int i = 2; i < n; i++)
                if (i != n-b && i != b && i != b+1)
                    rs[c++] = i;
            for (int i = 0; i < n-2; i++)
                rs[n-2+i] = rs[i] + n;
            printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, b, n+1, b+1, n, n-b, 2*n, b);
            for (int i = 1; i < 2*n-4; i++)
                printf("%d %d\n", rs[i-1], rs[i]);
            break;
    }

    return 0;
}
