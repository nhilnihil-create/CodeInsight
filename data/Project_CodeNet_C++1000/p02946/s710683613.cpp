#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int k, x;
    cin >> k >> x;
    for (int i = x-k+1; i <= x+k-1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}