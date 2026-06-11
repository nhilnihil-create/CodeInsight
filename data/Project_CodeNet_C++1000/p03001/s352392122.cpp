#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    double w,h,x,y;
    cin >> w >> h >> x >> y;

    printf("%.10f ", w*h/2);

    if (w/2==x && h/2==y) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    return 0;
}