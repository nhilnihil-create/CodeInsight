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
    int n; cin >> n;
    n *= 100;
    for (int i = 0; i < 100; i++) {
        if ((n+i) % 108 == 0) {
            cout << (n+i) / 108 << endl;
            return 0;
        }
    }

    cout << ":(" << endl;

    return 0;
} 