#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);

    map<string, int> words;
    rep(i, n) {
        if(words.count(s.at(i)) == 0) {
            words[s.at(i)] = 1;
        } else {
            words[s.at(i)]++;
        }
    }

    int maxCount = 0;
    for (pair<string, int> word : words) {
        maxCount = max(maxCount, word.second);
    }

    for (pair<string, int> word : words) {
        if(word.second == maxCount) {
            cout << word.first << endl;
        }
    }

    return 0;
}
