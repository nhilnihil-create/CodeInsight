#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000;

int main(){
    int a, b;
    cin >> a >> b;
    rep (i, 1010) {
        int aa = i * 8 / 100, bb = i * 10 / 100;
        if (aa == a && bb == b) {
            cout << i << endl;
            return 0;
        }
    }

    cout << "-1" << endl;

    return 0;
} 