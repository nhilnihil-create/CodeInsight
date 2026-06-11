#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,k;
    cin >> n >> k;
    if(k == 1){
        cout << 0 << endl;
    }else{
        cout << n - k<< endl;
    }
    return 0;
}