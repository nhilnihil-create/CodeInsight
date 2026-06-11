#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    int sum = n * l + n * (n-1) / 2;
    int min = abs(sum);
    rep(i, n) {
        int tmp = abs(sum - (sum - (i + l)));
        if (min > tmp) min = tmp;
    }
    if (sum > 0) cout << sum - min << endl;
    else cout << sum + min << endl;
}