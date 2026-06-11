#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s;
    vector<string>word;
    cin >> s;
    int cnt = 0, slen = s.size();
    word.push_back(s.substr(0, 1));
    for (int i = 1; i < slen; i++) {
        if (slen - i == 2) {
            if (s[slen - 1] == s[slen - 2]) {
                if (word[cnt] == s.substr(slen - 2, 2)) {
                    word[cnt] = s.substr(slen - 4, 3);
                    word.push_back(s.substr(slen - 1, 1));
                    break;
                }
                else {
                    word.push_back(s.substr(slen - 2, 2));
                    break;
                }
            }
        }
        if (word[cnt] != (s.substr(i, 1))) {
            word.push_back(s.substr(i, 1));
            cnt++;
        }
        else if (slen - i >= 2) {
            word.push_back(s.substr(i, 2));
            i++;
            cnt++;
        }
    }
    cout << word.size()<< endl;
    return 0;
}
