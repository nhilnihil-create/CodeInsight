#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    vector<pair<int,pii>> vec;
    int r = 0, l = 0, idx = 0;
    rep(i, S.size()) {
        if(S[i] == 'R') {
            r++;
            if(S[i + 1] == 'L')
                idx = i;
        }
        if(S[i] == 'L') {
            l++;
            if(i+1==S.size()||S[i + 1] == 'R') {
                vec.pb(MP(idx, MP(r, l)));
                l = 0, r = 0;
            }
        }
    }
    int N = S.size();
    vector<int> res(N);
    for(auto x:vec){
        int idx = x.first;
        int r = x.second.first,l=x.second.second;
        res[idx] = (r+1)/2+l/2;
        res[idx+1] = (l+1)/2+r/2;
    }
    rep(i,N){
        cout << res[i] << (i==N-1?"\n":" ");
    }
    return 0;
}