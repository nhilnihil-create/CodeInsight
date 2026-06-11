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
    int a[n], b[n], c[n - 1];
    rep(i, n) { cin >> a[i]; }
    rep(i, n) { cin >> b[i]; }
    rep(i, n - 1) { cin >> c[i]; }

    // 食べ物ごとの満足度をすべて足す
    int total = 0;
    rep(i, n) { total += b[i]; }

    // 連続している要素を抽出
    vector<int> conti;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1] + 1) {
            conti.push_back(a[i - 1]);
        }
    }
    /*
    for(auto i = conti.begin(); i != conti.end(); ++i) {
        cout << *i << ",";
    }
    cout << endl;
    */

    // 連続したモノの満足度を追加
    for(auto i = conti.begin(); i != conti.end(); ++i) {
        total += c[(*i) - 1];
    }

    // 表示
    cout << total << endl;
}