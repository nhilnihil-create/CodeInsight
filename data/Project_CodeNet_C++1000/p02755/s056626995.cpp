#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){

    double a,b;
    cin >> a >> b;

    rep(i, 1001) {
        int at = i * 0.08;
        int bt = i * 0.1;
        if (a == at && b == bt) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
} 
