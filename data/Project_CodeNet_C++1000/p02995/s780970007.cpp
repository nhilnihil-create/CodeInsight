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

ll gcd(ll a, ll b) {
    ll ans = 0;
    int temp;

    while(true) {

        if(a % b == 0) {
            ans = b;
            break;
        }

        temp = a % b;
        a = b;
        b = temp;
    }

    return ans;
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    // c,dの最大公約数l
    ll l = (c * d) / gcd(c, d);

    // B以下のcの倍数の個数
    ll b_c = b / c;
    // B以下のdの倍数の個数
    ll b_d = b / d;
    // B以下のlの倍数の個数
    ll b_l = b / l;

    // A以下のcの倍数の個数
    ll a_c = a / c;
    // A以下のdの倍数の個数
    ll a_d = a / d;
    // A以下のlの倍数の個数
    ll a_l = a / l;
    // 計算
    ll ans = (b - b_c - b_d + b_l) - (a - a_c - a_d + a_l);

    cout << ans << endl;
}