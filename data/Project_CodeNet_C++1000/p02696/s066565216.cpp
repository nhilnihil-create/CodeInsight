#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    //与式＝A*(x%B)-(Ax%B)でAx%B=A(x%B)%B←modを利用
    ll x;
    if (n >= b - 1)x = b - 1;
    else x = n;
    ll ans = (a * x) / b - a * (x / b);
    cout << ans << endl;
  

    return 0;
}