#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i,n) for (int i = 0; i < int(n); i++)

bool solve() {
    int n; cin >> n;

    map<int,int> cnt;
    forn(i,n) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> num, rep;
    for (auto kv : cnt) {
        num.push_back(kv.first);
        rep.push_back(kv.second);
    }

    if (num.size() == 1) {
        return num[0] == 0;
    }
    else if (num.size() == 2) {
        return num[0] == 0 && rep[0]*2 == rep[1];
    }
    else if (num.size() == 3) {
        return (num[0]^num[1]^num[2]) == 0 && (rep[0] == rep[1]) && (rep[1] == rep[2]);
    }
    else return false;
}

int main() {
    cout << (solve() ? "Yes" : "No");
    return 0;
}
