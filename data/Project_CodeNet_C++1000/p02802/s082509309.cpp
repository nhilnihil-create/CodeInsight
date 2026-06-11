#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

// C - Welcome to AtCoder

int main(void) {
    io;
    int total_prob, attemp;
    cin >> total_prob >> attemp;
    int ca = 0; // correct ans
    int at = 0; // total penalty
    int pcnt[total_prob] = {0}; // penalty count
    bool found[total_prob] = { false }; // correct found ?

    rep(i, attemp) {
        int val;
        string s;
        cin >> val >> s;
        val--;
        if (s == "AC" && (found[val] == false)) {
            ca++;
            found[val] = true;
            at += pcnt[val];
        } else {
            pcnt[val]++;
        }

    }
    cout << ca << " " << at;
    return 0;
}
