#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    string r, g, b;
    vector<int>rn, gn, bn;
    cin >> s;
    rep(i, n) {
        if (s[i] == 'R')r.push_back('R'); rn.push_back(i);
        if (s[i] == 'G')g.push_back('G'); gn.push_back(i);
        if (s[i] == 'B')b.push_back('B'); bn.push_back(i);
    }
    ll rs = r.size(),gs = g.size(),bs = b.size();
    //cout << rs << endl;
    ll ans = rs * gs * bs;
    rep(i, n) {
        rep(j, n/2+1) {
            if (i + 2 * j >= n)break;
            if (s[i] != s[i + j] && s[i + j] != s[i + 2 * j] && s[i] != s[i + 2 * j]) {
                ans--;
            }
        }
    }
    cout << ans << endl;


    return 0;
}