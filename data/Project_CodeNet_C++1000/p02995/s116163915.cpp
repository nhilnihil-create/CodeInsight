#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
long long lcm2(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}

int main()
{
    ll a, b,ans;
    ll c,d;

    cin >> a >> b >> c >> d;

    //a未満のcで割り切れる個数
    ll c1 = (a-1) / c;
    //b以下のcで割り切れる個数
    ll c2 = b / c;
    //a未満のdで割り切れる個数
    ll d1 = (a - 1) / d;
    //b以下のcで割り切れる個数
    ll d2 = b / d;
    //c*dの最小公倍数
    ll cd = lcm2(c, d);
    //a未満のc*dの公倍数で割り切れる個数
    ll cd1 = (a - 1) / cd;
    //b以下のc*dの公倍数で割り切れる個数
    ll cd2 = b / cd;

    ans = (b - a) + 1 - (c2 - c1) - (d2 - d1) + (cd2 - cd1);
    cout << ans << endl;

    return 0;
}
