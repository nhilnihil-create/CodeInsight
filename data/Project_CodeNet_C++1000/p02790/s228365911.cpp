#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        rep(i,a) printf("%d", b);
        printf("\n");
    }
    else {
        rep(i,b) printf("%d", a);
        printf("\n");
    }
    return 0;
}