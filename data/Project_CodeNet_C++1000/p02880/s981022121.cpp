#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    rep(i,10) rep(j,10){
        if(i*j == n) {
            cout << "Yes" << endl;
            return 0;
        } 
    }
    cout << "No" << endl;
    return 0;
}