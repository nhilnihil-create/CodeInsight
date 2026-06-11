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
    vector<int>a(n);
    rep(i, n)cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 2;
    ll ans = a[0];
    int j = 0;
    while (cnt < n) {
        j++;
        rep(i, 2) {
            cnt++;
            if (cnt > n)break;
            ans += a[j];
       }
    }
    cout << ans << endl;

    return 0;
}