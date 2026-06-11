#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a;
    cin >> a;
    int aa = a*a;
    int aaa = aa * a;
    cout << a+aa+aaa << endl;
    return 0;
}