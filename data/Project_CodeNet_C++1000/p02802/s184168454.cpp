#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> a(n);
    while (m--) {
        int x;
        cin >> x; x--;
        string s;
        cin >> s;
        a[x].push_back(s);
    }

    int wa = 0;
    int ac = 0;
    for (auto x : a) {
        bool counts = false;
        int wrong = 0;
        for (int i = 0; i < (int)x.size(); i++) {
            if (x[i] == "WA") wrong++;
            else {
                counts = true;
                ac++;
                break;
            }
        }
        if (counts) wa += wrong;
    }

    cout << ac << " " << wa << endl;
    
	return 0;
}