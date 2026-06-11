#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<stack>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
const double PI = acos(-1);  // PI = 3.141593...

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s = "N" + s + "N";

    char target = 'L';
    if(s[1] == 'L') target = 'R';
    vector<int> pos;
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        if(s[i] == 'R' && s[i+1] == 'R') ++ans;
        if(s[i] == 'L' && s[i-1] == 'L') ++ans;
        if(s[i] == target && s[i+1] != target) pos.emplace_back(i);
    }

    for(int i : pos) {
        if(k > 0) {
            if(i == n) ++ans;
            else ans += 2;
            --k;
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}