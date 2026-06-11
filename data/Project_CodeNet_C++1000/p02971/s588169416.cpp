#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], a_array[n];

    // 最大値決定
    int first = 0;
    rep(i, n) {
        cin >> a[i];
        a_array[i] = a[i];
        first = max(a[i], first);
    }

    // 最大値を一つ0にする
    rep(i, n) {
        if(first == a[i]) {
            a[i] = 0;
            break;
        }
    }

    // 二番目を探す
    int second = 0;
    rep(i, n) { second = max(a[i], second); }

    rep(i, n) {
        if(a_array[i] != first) {
            cout << first << endl;
        } else {
            cout << second << endl;
        }
    }
}