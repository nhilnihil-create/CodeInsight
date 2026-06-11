#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,k;
    cin >> k;
    cin >> a >> b;
    int i = 0;
    while(k*i < 1001){
        if(a <= k*i && k*i <= b){
            cout << "OK" << endl;
            return 0;
        }
        i++;
    }
    cout << "NG" << endl;
    return 0;
}