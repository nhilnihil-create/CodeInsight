#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<vector<string>> ds(n+1);
    ds[1].push_back("a");
    for (int i = 2; i <= n; ++i) {
        vector<vector<string>> ds2(n+1);
        for (int j = 1; j < i; ++j) {
            for (auto& s :ds[j]) {
                for (int k = 0; k <= j; ++k) {
                    char t = 'a' + k;
                    int ij = j + (k == j); 
                    ds2[ij].emplace_back(s + t); 
                }
            }
        }
        swap(ds, ds2); 
    }
    vector<string> ret;
    rng(i,1, n+1) ret.insert(ret.end(), ds[i].begin(), ds[i].end());
    sort(all(ret));
    for (auto& s : ret) cout << s << endl; 
    
    return 0;
}