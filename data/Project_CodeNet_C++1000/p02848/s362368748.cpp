#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int size = s.length();
    rep(i,size) {
        int a = s[i]+n;
        if(a > 90) a -= 26;
        printf("%c",a);
    }
    cout << endl;
    return 0;
}