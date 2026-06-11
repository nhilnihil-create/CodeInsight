#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string s, t;

int main() {
    cin >> s >> t;
    int slen = s.length(); int tlen = t.length();

    vector<int> salp(26, 0);
    vector< vector<int> > spos(26, vector<int>());
    for(int i = 0; i < slen; ++i) {
        int alpin = s.at(i) - 'a';
        salp.at(alpin)++;
        spos.at(alpin).emplace_back(i);
    }

    set<char> tst;
    for(int i = 0; i < tlen; ++i) tst.insert(t.at(i));

    bool flg = true;
    for(auto x : tst) {
        int talp = x - 'a';
        if(salp.at(talp) == 0) {
            flg = false;
            break;
        }
    }


    if(!flg) {
        cout << -1 << endl;
    }else {
        long long cnt = 0;
        long long now = -1;
        for(int i = 0; i < tlen; ++i) {
            char check = t.at(i);
            int tch = check - 'a';
            bool fflg = false;

            // nowに関して二部探索
            int chno = upper_bound(spos.at(tch).begin(), spos.at(tch).end(), now) - spos.at(tch).begin();
            int sposlen = spos.at(tch).size();
            if(chno == sposlen) {
                now = spos.at(tch).at(0);
                cnt++;
            }else {
                now = spos.at(tch).at(chno);
            }
            // cout << "cnt " << cnt << " now " << now << endl;
        }

        cout << (long long)slen * cnt + now + 1 << endl;
    }
}