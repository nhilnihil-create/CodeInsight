//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vs ss;
    rep(i, s.size()) {
        if(!i) ss.push_back(s.substr(0, 1));
        else {
            if(s.substr(i, 1) == ss[ss.size()-1]) {
                if(i == s.size()-1) {
                    ss[ss.size()-1] += s[i];
                }
                else ss.push_back(s.substr(i++, 2));
            } else {
                ss.push_back(s.substr(i, 1));
            }
        }
    }

    //rep(i, ss.size()) cout << ss[i] << endl;

    cout << (int)ss.size() << endl;
}