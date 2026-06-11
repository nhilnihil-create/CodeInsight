#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        int iid = s.find(to_string(i));
        if (iid == string::npos) continue;

        for (int j = 0; j < 10; ++j) {
            string sj = s.substr(iid + 1);
            int jid = sj.find(to_string(j));
            if (jid == sj.length() - 1) continue;
            if (jid == string::npos) continue;

            for (int k = 0; k < 10; ++k) {
                string sk = sj.substr(jid + 1);
                int kid = sk.find(to_string(k));
                if (kid != string::npos){
                    res++;
                }
            }
        }
    }
    cout << res << endl;
}