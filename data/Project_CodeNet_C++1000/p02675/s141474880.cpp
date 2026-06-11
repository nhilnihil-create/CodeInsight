#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define scanInt(a) scanf("%d", &a)
using namespace std;

int main() {
    int a;
    scanInt(a);
    if (a % 10 == 3) printf("bon\n");
    else if (a % 10 == 0 ||
        a % 10 == 1 ||
        a % 10 == 6 ||
        a % 10 == 8) printf("pon\n"); 
    else printf("hon\n");
    return 0;
}
