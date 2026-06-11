#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    bool flg = true;
    int slen = s.length();
    if(slen % 2 != 0) flg = false;

    if(flg) {
        for(int i = 0; i < slen; ++i) {
            if(i % 2 == 0) {
                if(s.at(i) != 'h') flg = false;
            }else {
                if(s.at(i) != 'i') flg = false;
            }
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}