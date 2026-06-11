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
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[m];
    int res[n];
    REP(i, n)
        REP(j, m)
            cin >> a[i][j];
    REP(i, m)
        cin >> b[i];
    REP(i, n){
        res[i] = 0;
        REP(j, m)
            res[i] += (a[i][j] * b[j]);
        }

    REP(i, n)
        cout << res[i] << endl;

    return 0;
}