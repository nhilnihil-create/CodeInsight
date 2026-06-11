#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
   ll A, B, C, D;
   cin >> A >> B >> C >> D;

    //Cで割り切れる個数
    ll div_C = B / C - A / C + 1;
    //Dで割り切れる個数
    ll div_D = B / D - A / D + 1;
    //最小公倍数CDで割り切れる個数
    ll CD = lcm(C, D);
    ll div_CD = B / (CD) - A / (CD) + 1;
    if(A % C != 0) div_C--;
    if(A % D != 0) div_D--;
    if(A % (CD) != 0) div_CD--;
    cout << (B - A + 1) - (div_C + div_D - div_CD);
}