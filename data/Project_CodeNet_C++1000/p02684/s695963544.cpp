#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
const int MAX = 2e5;
int n;
ll k; 
int a[MAX]; 
bool visited[MAX];
int main() {
    ll ans = 0;
    cin >> n >> k;
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    int pos = 0;
    visited[pos] = true;
    int cnt = 0;
    rep(i, n) {
        cnt++;
        pos = a[pos];
        if (visited[pos]) break;
    }
    int loop_start = pos;
    if (cnt >= k) {
        pos = 0;
        rep(i, k) {
            pos = a[pos];
        }
        ans = pos;
    } else {
        pos = 0;
        rep(i, n) {
            if (pos == loop_start) break;
            pos = a[pos];
            cnt--;
            k--;
        }
        int loop_size = cnt;
        pos = loop_start;
        rep(i, k%loop_size) {
            pos = a[pos];
        }
        ans = pos;
    }
    ans++;
    cout << ans << endl;
}