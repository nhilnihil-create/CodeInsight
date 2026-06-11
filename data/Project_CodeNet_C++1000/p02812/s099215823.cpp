// 基本のinclude
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

string sp = "ABC";

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    rep(i, s.size()-2) {
        if (s[i] == sp[0] && s[i+1] == sp[1] && s[i+2] == sp[2]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}