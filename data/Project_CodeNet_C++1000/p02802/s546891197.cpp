#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int n_probs, m_submissions;
    cin >> n_probs >> m_submissions;
    int cnt[n_probs] = {0}; // Penalty count
    bool found[n_probs] = { false }; // AC bool
    int correct_ans = 0, penalties = 0;

    rep(i, m_submissions) {
        int val;
        string s;
        cin >> val >> s;
        val--; // To get index right
        if (s == "AC" && found[val] == false) { // First time "AC"
            found[val] = true;
            correct_ans++; 
            penalties += cnt[val];
        } else {
            cnt[val]++;
        }
    }
    cout << correct_ans << " " << penalties;
    return 0;
}
