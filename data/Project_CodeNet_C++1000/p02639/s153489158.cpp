#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define erep(i, n) for (int i = 0; i <= (n); i++)
#define erep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;

int main() {
    int x[6];
    int a;
    erep1(i, 5) cin >> x[i];
    erep1(i, 5) {
        if (x[i] == 0) {
            a = i;
            break;
        }
    }
    cout << a << endl;
}