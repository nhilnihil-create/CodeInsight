#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h1,h2,m1,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    if(m1 != 0 ) cout << (h2-h1-1)*60+(60-m1)+m2 - k << endl;
    else cout << (h2-h1)*60+m2 - k << endl;
    return 0;
}