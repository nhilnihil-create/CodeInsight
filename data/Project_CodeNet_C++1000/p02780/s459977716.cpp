#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>p(n);
    rep(i, n)cin >> p[i];
    //最初からk番目までを足してそこから足し引きして動かす
    int s = 0;
    rep(i, k)s += p[i];
    int sm = s;
    rep(i, n - k) {
        s -= p[i];
        s += p[i + k];
        sm = max(s, sm);
    }
    double ans = sm + k;
    ans = ans / 2.0;
    
    
    printf("%.16f", ans);

    return 0;
}