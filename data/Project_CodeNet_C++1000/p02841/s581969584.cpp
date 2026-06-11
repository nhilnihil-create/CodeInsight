#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int m1,m2,d1,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if(m2 == m1 + 1) cout << "1" << endl;
    else cout << 0 << endl;
    return 0;
}