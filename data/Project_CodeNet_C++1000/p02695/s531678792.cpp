#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pi;
const ll inf = 1e18 + 1;
const ll limit = 1e9;

int n,m,q;
int ans = 0;
int a[100];
int b[100];
int c[100];
int d[100];

int score(vector<int> s) {
    int res = 0;
    for (int i = 0; i < q; i++) {
        int pre = s[a[i]-1] - '0';
        int nex = s[b[i]-1] - '0';
        if (nex - pre == c[i]) res += d[i];
    }
    return res;
}

void dfs(vector<int> s) {
    if (s.size() == n) {
        ans = max(ans,score(s));
        return;
    }    
    int last = 1;
    if (s.size()) last = s[s.size()-1];
    for (int i = last; i <= m; i++) {
        s.push_back(i);
        dfs(s);
        s.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> v;
    dfs(v);
    cout << ans << "\n";
}   
 