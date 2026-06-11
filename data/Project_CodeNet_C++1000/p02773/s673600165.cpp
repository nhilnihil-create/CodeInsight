#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n; cin >> n;
    map<string,int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int mx = 0;
    for (auto p : mp) mx = max(mx, p.second);
    for (auto p : mp) {
        if (p.second != mx) continue;
        cout << p.first << endl;
    }

    return 0;
}