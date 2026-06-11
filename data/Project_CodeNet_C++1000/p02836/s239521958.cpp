#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int size = s.length();
    int sizeh = size/2;
    int j = size-1;
    int ans = 0;
    rep(i,sizeh){
        if(s[i] != s[j]) ans++;
        j--;
    }
    cout << ans << endl;
    return 0;
}