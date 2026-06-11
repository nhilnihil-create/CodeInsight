#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> snk(n);
    rep(i,k){
        int d;
        cin >> d;
        rep(j,d){
            int a;
            cin >> a;
            a = a - 1;
            snk[a]++;
        }
    }
    int ans = 0;
    rep(i,n){
        if(snk[i] == 0) ans++;
    }
    cout << ans << endl;
}