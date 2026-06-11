#include<iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    long long a, b, c, d;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &d);

    a--;
    ll cd = lcm(c, d);
    ll nb = b / c + b / d - b / cd;
    ll na = a / c + a / d - a / cd;

    cout << b - a - (nb - na) << endl;
}