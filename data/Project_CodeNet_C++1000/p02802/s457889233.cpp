#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<string>> JUDGES(N);
    rep(i, M) {
        int p;
        string s;
        cin >> p >> s;
        --p;
        JUDGES[p].push_back(s);
    }
    
    int AC = 0;
    int WA = 0;

    for(auto jds: JUDGES) {
        int wacnt = 0;
        for(string jd: jds) {
            if(jd == "AC") {
                ++AC;
                break;
            }
            else {
                ++wacnt;
            }
        }
        if(wacnt==jds.size()) {
            continue;
        }
        else {
            WA += wacnt;
        }
    }

    cout << AC << " " << WA << endl;

    return 0;
}