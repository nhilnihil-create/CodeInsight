#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    rep(i, n) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }

    map<string, ll> mp;
    ll count = 0;

    rep(i, n) {
        if(mp[s[i]] > 0) {
            count += mp[s[i]];
        }
        mp[s[i]]++;
    }
    cout << count << endl;
}