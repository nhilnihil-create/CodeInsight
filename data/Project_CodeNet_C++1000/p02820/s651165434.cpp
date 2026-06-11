#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    map<char, int> point{{'r', p}, {'s', r}, {'p', s}};
    vector<bool> win(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i - k + 1 <= 0) {
            ans += point[t[i]];
            win[i] = true;
        } else {
            if (t[i-k] == t[i] && win[i-k]) win[i] = false;
            else {
                ans += point[t[i]];
                win[i] = true;
            }
        }
    }

    cout << ans << endl;
}