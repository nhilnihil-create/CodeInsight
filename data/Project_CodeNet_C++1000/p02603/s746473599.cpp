#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findNextBottom(vector<int> prices, int start) {
    int bottom = -1;
    if (start == 0) {
        bottom = 0;
    }
    for (int i = start + 1; i < prices.size(); i++) {
        if (bottom < 0) {
            if (prices[start] > prices[i]) {
                bottom = i;
                continue;
            } else if (prices[start] == prices[i]) {
                continue;
            } else {
                return -1;
            }
        } else {
            if (prices[bottom] > prices[i]) {
                bottom = i;
                continue;
            } else if (prices[bottom] == prices[i]) {
                continue;
            } else {
                return bottom;
            }
        }
    }
    return bottom;
}

int findNextPeak(vector<int> prices, int start) {
    int peak = -1;
    for (int i = start + 1; i < prices.size(); i++) {
        if (peak < 0) {
            if (prices[start] < prices[i]) {
                peak = i;
                continue;
            } else if (prices[start] == prices[i]) {
                continue;
            } else {
                return -1;
            }
        } else {
            if (prices[peak] < prices[i]) {
                peak = i;
                continue;
            } else if (prices[peak] == prices[i]) {
                continue;
            } else {
                return peak;
            }
        }
    }
    return peak;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long money = 1000LL;
    long long stock = 0;
    int date = 0;

    while (date < n) {
        int nextBottom = findNextBottom(a, date);
        if (nextBottom < 0) {
            break;
        }
        int nextPeak = findNextPeak(a, nextBottom);
        if (nextPeak < 0) {
            break;
        }
        // 直近の谷日が見つかれば、買う
        long long buy = money / a[nextBottom];
        money = money - buy * a[nextBottom];
        stock = stock + buy;
        // 直近の山頂日が見つかれば、売る
        money = money + stock * a[nextPeak];
        stock = 0;
        // 最終締め日に更新
        date = nextPeak;
    }

    cout << money << endl;

    return 0;
}
