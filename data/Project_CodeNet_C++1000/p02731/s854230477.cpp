// C - Mazimum Volume
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    double l;
    cin >> l;
    double ans = 1.0;
    ans = l/3*l/3*l/3;
    printf("%.20f\n", ans);
    return 0;
}