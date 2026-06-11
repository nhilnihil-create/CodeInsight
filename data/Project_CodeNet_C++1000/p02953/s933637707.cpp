//確認用
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() { 
    int n;
    cin >> n;
    int ma = 0;
    vector<int> h(n);
    int k;
    rep(i, n) cin >> h[i];
    rep(i, n) {
        if(ma <= h[i]) ma = h[i];
        else if(ma - 1 > h[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
