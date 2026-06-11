#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), idx(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        idx[a[i]] = i;
    }
    set<int> s;
    ll ans = 0;
    for(int x = n-1; x >= 0; x--){
        int i = idx[x];
        ll c = 0;
        s.insert(i);
        vector<int> l(2, -1), r(2, n);
        auto it = s.find(i);
        rep(j,2){
            if(it == s.begin()) break;
            --it;
            l[j] = *it;
        }
        it = s.find(i);
        rep(j,2){
            ++it;
            if(it == s.end()) break;
            r[j] = *it;
        }
        vector<int> ls(2);
        ls[0] = i - l[0]; ls[1] = l[0] - l[1];
        vector<int> rs(2);
        rs[0] = r[0] - i; rs[1] = r[1] - r[0];
        c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
        ans += c * (x+1);
    }
    cout << ans << endl;
	return 0;
}