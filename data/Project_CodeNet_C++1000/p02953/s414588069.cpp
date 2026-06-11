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
    int h[n];
    rep(i, n) { cin >> h[i]; }

    if(n == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    // 先頭は下げ確定
    h[0]--;

    // ２番目から見ていく
    // ひとつ前より高ければ下げる
    for(int i = 1; i < n; ++i) {
        if(h[i - 1] < h[i]) {
            h[i]--;
        }
    }
    /*
    rep(i, n) { cout << h[i] << ","; }
    cout << endl;
    */
    int flag = 1;
    for(int i = 1; i < n; ++i) {
        if(h[i - 1] > h[i]) {
            flag = 0;
            break;
        }
    }

    if(flag == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
