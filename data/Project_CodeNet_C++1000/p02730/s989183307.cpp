#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >>s;
    int sl = s.size();
    bool kaibun = true;
    for (int i = 0; i < sl; i++) {
        if (i < sl/2 + 1) {
            if (s.at(i) != s.at(sl - i - 1)) {
                kaibun = false;
                break;
            }
        }
        if (i < sl/4 + 1) {
            if (s.at(i) != s.at((sl - 1)/2 - i - 1)) {
                kaibun = false;
                break;
            }
        }
        if (i >= (sl + 3) /2 - 1 && i < sl * 3 / 4) {
            if (s.at(i) != s.at(sl  - (i - sl/2))) {
                kaibun =false;
                break;
            }
        }
    }
    if (kaibun) cout << "Yes" << endl;
    else cout << "No" << endl;

}