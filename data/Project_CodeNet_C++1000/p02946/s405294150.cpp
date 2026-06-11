#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, x;
    cin >> k >> x;

    Rep (i, x-k+1,x+k) {
        printf("%d ", i);
    }
    printf("\n");
}