
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    string s; cin >> s;
    char bf=' ';
    bool flag = false;
    int cnt = 0;
    rep(i, 0, s.size()) {
        if (flag) {
            cnt++;
            flag = false;
            continue;
        }
        if(s[i] == bf) {
            bf = ' ';
            flag = true;
        }
        else {
            bf = s[i];
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
