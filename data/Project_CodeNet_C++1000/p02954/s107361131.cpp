//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vi ans(n);
    rep(i, n-1) {
        int st = i;
        int num = -1;
        while(s[i] != 'L' || s[i+1] != 'R') {
            if(num == -1 && s[i+1] == 'L') {
                num = i+1;
            }
            
            ++i;
            if(i == n-1) break;
        }
        if((i-num)&1) {
            ans[num-1] = (i-st+2)/2;
            ans[num] = (i-st+1)/2;
        } else {
            ans[num] = (i-st+2)/2;
            ans[num-1] = (i-st+1)/2;
        }
    }

    rep(i,n) {
        cout << ans[i] << (i != n-1 ? ' ' : '\n');
    }
}