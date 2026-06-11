#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n, m, x,price = 0,p=1000000005,check=0;
    cin >> n >> m >> x;
    vector<int>c(n);
    vector<int>ans(m);
    rep(i, m)ans[i] = 0;
    vector<vector<int>>a(n,vector<int>(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    //それぞれの本に対して買うor買わないのbit全探索
    rep(is, 1 << n) {
        price = 0;
        rep(i,n){
            if (is >> i & 1) {//bitが立っていたら、理解度を各アルゴリズムに対してプラス。また合計金額も記録
                rep(j, m) {
                    ans[j] += a[i][j];
                }
                price += c[i];
            }
        }
        int cnt = 0;
        rep(j, m) {
            if (ans[j] >= x)cnt++;
            ans[j] = 0;
        }
        if (cnt == m) {
            if (price < p)p = price;//最低価格の更新
            check = 1;
        }
    }
    if (check == 0)cout << -1 << endl;
    else cout << p << endl;

    return 0;
}