#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n%3 > 0) {
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else {
        map<int,int> cnt;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<pair<int,int>> vec;
        for(auto t : cnt) {
            vec.push_back({t.first, t.second});
        }
        if(vec.size() > 3) cout << "No" << endl;
        else if(vec.size() == 3) {
            int Xor = 0;
            bool cnt_ok = 1;
            for(int i = 0; i < 3; i++) {
                Xor ^= vec[i].first;
                if(vec[i].second != n/3) cnt_ok = 0;
            }
            if(cnt_ok && Xor == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(vec.size() == 2) {
            int cnt_x = vec[0].second, x = vec[0].first;
            int cnt_y = vec[1].second, y = vec[1].first;
            if(cnt_x == (n/3) && x == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            if(vec[0].first == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}

