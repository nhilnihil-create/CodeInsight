#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, a;
    cin >> N;
    map<int, int> mp;
    rep(i,N) {
        cin >> a;
        ++mp[a];
    }
    bool ok = true;
    if (N % 3 == 0 && mp[0] == N / 3) {
        for (auto x : mp) {
            if (x.first != 0 && x.second % 2 != 0) ok = false;
        }
    } else if (mp[0] != N && mp[0] > 0) ok = false;
    else if (mp[0] == 0) {
        if (mp.size()-1 != 3) ok = false;
        else {
            vector<int> num(4),cnt(4);
            int i = 0;
            for (auto x : mp) {
                num.at(i) = x.first;
                cnt.at(i) = x.second;
                ++i;
            }
            rep(i,3) if ((num.at(i%3+1) ^ num.at((i+1)%3+1)) != num.at((i+2)%3+1)) ok = false;
            rep(i,3) if (cnt.at(i%3+1) != cnt.at((i+1)%3+1)) ok = false;
        } 
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

