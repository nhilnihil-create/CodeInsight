#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while(a > 0 && c > 0){
        c = c - b;
        a = a - d;
    }
    if(c <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}