#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int m = (n-1)/2;
    int k = (n+3)/2;
    bool flg = true;
    rep(i, n/2) {
        if (s[i] != s[n-1-i]) flg = false; 
    }
    rep(i, m/2) {
        if (s[i] != s[m-1-i]) flg = false;
    }
    //cout << flg << endl;
    for (int i = k/2-1; i < n; ++i) {
        if (s[i] != s[n-1-i]) flg = false;
    }
    cout << ((flg) ? "Yes" : "No") << endl;
    return 0;
}