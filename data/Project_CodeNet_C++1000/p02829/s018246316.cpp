#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b;
    cin >> a >> b;
    if(a*b == 2) cout << 3 << endl;
    if(a*b == 3) cout << 2 << endl;
    if(a*b == 6) cout << 1 << endl;
    return 0;
}