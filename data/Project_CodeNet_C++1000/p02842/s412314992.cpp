#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> y(50000);
    rep(i,50000){
        y[i] = i*1.08;
    }
    rep(i,50000){
        if(y[i] == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}