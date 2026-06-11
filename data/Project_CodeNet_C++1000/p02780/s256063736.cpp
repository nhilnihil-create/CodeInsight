#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
/* ------------------------------------------------ */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ------------------------------------------------ */

int main() {
    int n, k;
    cin >> n >> k;
    double a[200100];
    a[0] = 0;
    rep1(i, n) {
        double A;
        cin >> A;
        A = (A+1)/2;
        a[i] = A;
        a[i] += a[i-1];
    }
    double ma = -1;
    rep(i, n - k + 1) ma = max(ma, a[i + k] - a[i]);
    cout << fixed << setprecision(10) << ma << endl;
    return 0;
}