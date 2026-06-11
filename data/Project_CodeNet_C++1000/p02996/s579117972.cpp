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

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)


int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > pairs(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        pairs[i] = make_pair(b, a);
    }
    sort(pairs.begin(), pairs.end());//pairのソートは第一成分で実行される
    rep(i, n) {
        if (i != 0)pairs[i].second += pairs[i - 1].second;
        if (pairs[i].second > pairs[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}