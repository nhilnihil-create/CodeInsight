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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> l, r, cnt(n, 0), ans(n, 0);
    rep(i, n) {
        if (s[i] == 'L')l.push_back(i);//Lの位置をメモ
        if (s[i] == 'R')r.push_back(i);
    }
    int k = 0, q = r.size();
    rep(i, n) {
        if (i > l[k])k++;
        int p = n - 1 - i;
        if (p < r[q - 1])q--;
        if (s[i] == 'R') {
            cnt[i] = l[k] - i;//最寄りのLまでの必要な移動回数
            if (cnt[i] % 2 == 0)ans[l[k]]++;
            else ans[l[k] - 1]++;
        }
        if(s[p] == 'L') {
            cnt[p] = p - r[q - 1];
            if (cnt[p] % 2 == 0)ans[r[q - 1]]++;
            else ans[r[q - 1] + 1]++;
        }
    }
    rep(i, n-1)cout << ans[i] << ' ';
    cout << ans[n - 1] << endl;
  
    return 0;
}