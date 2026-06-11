#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int k = 0;
    rep(i,n){
        if(p[i] != i+1) k++;
    }
    if(k < 3) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}