#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int d(ll n) {
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int g_3(int n, int i) {
    if(i == 0) return n % 10;
    if(i == 1) return n / 10 % 10;
    if(i == 2) return n / 100;
}

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> ma;
    bool bo[5];
    fill(bo, bo + 5, false);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a = n - a;
        if(ma.count(a) && ma[a] != b) {
            cout << -1 << endl;
            return 0;
        }
        ma[a] = b;
        bo[a] = true;
    }
    bool ok = false;
    for(int i = ma[2] * 100 + ma[1] * 10 + ma[0] * 1; i < 1000; i++) {
        if(d(i) == n) {
            ok = true;
            rep(j, n) {
                if(bo[j]) {
                    if(ma[j] != g_3(i, j)) ok = false;
                }
            }
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}