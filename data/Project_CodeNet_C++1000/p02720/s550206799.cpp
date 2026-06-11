#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    ll K;
    cin >> K;

    if (K < 10) {
        cout << K << endl;
        return 0;
    }

    vector<vector<string>> lunluns(12);
    for (ll i = 1; i < 10; i++) {
        lunluns[1].push_back(to_string(i));
    }
    ll cnt = 9;
    ll order = 1;
    while (cnt < K) {
        for (auto l : lunluns[order]) {
            if (*l.rbegin() == '0') {
                lunluns[order + 1].push_back(l + "0");
                lunluns[order + 1].push_back(l + "1");
                cnt += 2;
            } else if (*l.rbegin() == '9') {
                lunluns[order + 1].push_back(l + "8");
                lunluns[order + 1].push_back(l + "9");
                cnt += 2;
            } else {
                ll last_digit = *l.rbegin() - '0';
                lunluns[order + 1].push_back(l + to_string(last_digit - 1));
                lunluns[order + 1].push_back(l + to_string(last_digit));
                lunluns[order + 1].push_back(l + to_string(last_digit + 1));
                cnt += 3;
            }
        }
        order++;
    }

    vector<string> flat;
    for (auto lo : lunluns) {
        for (auto s : lo) {
            flat.push_back(s);
        }
    }
    cout << flat[K - 1] << endl;
}
