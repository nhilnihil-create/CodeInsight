#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    double L;
    cin >> L;
    double x, y, z;
    x = L/3, y = L/3, z = L/3;
    double ans = x * y * z;
    printf("%.7f\n", ans);
    return 0;
}
