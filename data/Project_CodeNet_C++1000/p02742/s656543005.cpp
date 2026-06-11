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
    ll h, w;
    cin >> h >> w;
    ll a;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }

    else if (h % 2 == 0 || w % 2 == 0) {
        a = h * w / 2;
        cout << a << endl;
        return 0;
    }

    else {
        a = (h * w + 1) / 2;
        cout << a << endl;
        return 0;
    }

    return 0;
} 