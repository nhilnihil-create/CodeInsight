#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)


int main() {
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans;
    ans = (ll)w * h;
    ans = (double)ans / 2;
    int cnt = 0;
    if (w == x * 2 && h == y * 2)cnt = 1;
    printf("%.16f", ans);
    cout << ' ' << cnt << endl;

    return 0;
}