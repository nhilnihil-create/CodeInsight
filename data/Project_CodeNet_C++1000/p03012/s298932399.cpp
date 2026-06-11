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

int calc(int total, int num) {
    int s1 = num;
    int s2 = total - num;
    return abs(s1 - s2);
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    vector<int> cumulative_sum(n, 0);
    int total = 0;
    rep(i, n) {
        cin >> w[i];
        total += w[i];
    }

    // 累積和
    cumulative_sum[0] = w[0];
    for(int i = 1; i < n; i++) {
        cumulative_sum[i] = cumulative_sum[i - 1] + w[i];
    }

    // 半分を求める
    int mid = total / 2;

    // 半分より大きい和になった番号を求める
    int temp = n - 1;
    rep(i, n) {
        if(cumulative_sum[i] >= mid) {
            temp = i;
            break;
        }
    }

    // 求めた番号とそのひとつ前について、s1,s2の差を求める
    int right = calc(total, cumulative_sum[temp]);
    int left = calc(total, cumulative_sum[temp - 1]);

    cout << min(right, left) << endl;
}