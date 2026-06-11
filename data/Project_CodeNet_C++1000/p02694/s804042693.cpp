#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll x, money = 100;
    ll year = 0;
    cin >> x;
    while(1) {
        year++;
        money = money + money / 100;
        if(money >= x) {
            cout << year << endl;
            break;
        }
    }
    return 0;
}