#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
#define mod 1000000007
ll a[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll num1 = 0;
    ll num2 = 0;
    ll num3 = 0;
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        if ((a[i] == num1) && (a[i] == num2) && (a[i] == num3)) {
            num1++;
            ret = ret * 3 % mod;
        }
        else if ((a[i] == num1) && (a[i] == num2)) {
            num1++;
            ret = ret * 2 % mod;
        }
        else if ((a[i] == num2) && (a[i] == num3)) {
            num3++;
            ret = ret * 2 % mod;
        }
        else if ((a[i] == num3) && (a[i] == num1)) {
            num3++;
            ret = ret * 2 % mod;
        }
        else if (a[i] == num1) {
            num1++;
        }
        else if (a[i] == num2) {
            num2++;
        }
        else if (a[i] == num3) {
            num3++;
        }
        else {
            ret = 0;
        }
    }
    cout << ret << endl;
    return 0;
}