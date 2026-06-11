#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    string s,ft,bk;
    int q, t;
    cin >> s >> q;
    int chk = 0;
    rep(i, q) {
        cin >> t;
        if (t == 1)chk++;//chkが偶数の時は入れ替わりなし、奇数では入れ替わっている状態
        if (t == 2) {
            int f;
            string c;
            cin >> f >> c;
            if (f == 1) {
                if (chk % 2 == 0) {//そのまま前
                    ft = c + ft;
                }
                else {//入れ替わり状態なので後ろに
                    bk += c;
                }
            }
            else {
                if (chk % 2 == 0) {
                    bk += c;
                }
                else {
                    ft = c + ft;
                }
            }
        }
    }
    
    if (chk % 2 == 0) cout << ft <<  s << bk <<  endl;
    else {
        s = ft + s + bk;
        int n = s.size();
        rep(i,n) {
            cout << s[n - 1 - i];
        }
    }
    return 0;
}