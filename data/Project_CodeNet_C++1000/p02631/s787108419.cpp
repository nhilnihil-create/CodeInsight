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


using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)


int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<string>s(n);
    rep(i, n) {
        stringstream ss;
        cin >> a[i];
        ss << static_cast<bitset<32>>(a[i]);
        s[i] = ss.str();
    }
    int cnt[32] = { 0 };
    rep(i, n) {
        rep(j, 32) {
            if (s[i][j] == '1')cnt[j]++;
        }
    }
    rep(i, n) {
        int tmp[32], tmp2[32] = { 0 };
        string ans(32,'0');
        rep(j, 32) {
            if (s[i][j] == '1') {
                tmp[j] = cnt[j] - 1;
                tmp2[j]++;
            }
            else tmp[j] = cnt[j];
        }
        rep(j, 32) {
            tmp2[j] *= n;
            tmp[j] *= (n - 1);
            if ((max(tmp2[j], tmp[j]) - min(tmp2[j], tmp[j])) % 2 == 1) {
                ans[j] = '1';
            }
            else ans[j] = '0';
           
        }
        ll anst = stoi(ans, 0, 2);
        cout << anst << endl;
    }

    
    return 0;
}