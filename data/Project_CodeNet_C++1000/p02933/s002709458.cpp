#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a;
    string s;
    cin >> a >> s;
    if(a >= 3200) cout << s << endl;
    else cout << "red" << endl;
    return 0;
}