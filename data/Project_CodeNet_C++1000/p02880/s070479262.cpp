#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int seki;
    for (int i = 1; i <= 9; i++) {
        if (n % i == 0 && n / i <=9) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}