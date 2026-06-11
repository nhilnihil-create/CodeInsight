#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    int w, h, x, y, r;
    cin >> w >> h >> x >> y >> r;
    if(x - r < 0 || x + r > w || y - r < 0 || y + r > h)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}