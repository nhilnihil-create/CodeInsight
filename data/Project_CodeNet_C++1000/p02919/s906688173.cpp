#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)
int p[100000];
int idx[100000];
int main(){
    int n;
    cin >> n;
    rep(i,0,n) cin >> p[i];
    rep(i,0,n) --p[i];
    rep(i,0,n) idx[p[i]] = i;
    set<int> s;
    ll ans = 0;
    for(int x = n - 1; 0 <= x; x--){
        s.insert(idx[x]);
        ll c = 0;
        vector<int> l(2,-1);
        vector<int> r(2,n);
        {
            auto it = s.find(idx[x]);
            rep(i,0,2){
                if(it == s.begin()) break;
                it--;
                l[i] = *it;
            }
        }
        {
            auto it = s.find(idx[x]);
            rep(i,0,2){
                it++;
                if(it == s.end()) break;
                r[i] = *it;
            }
        }
        vector<int> ls(2);
        ls[0] = idx[x] - l[0]; ls[1] = l[0] - l[1];
        vector<int> rs(2);
        rs[0] = r[0] - idx[x]; rs[1] = r[1] - r[0];
        c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
        ans += c * (x+1);
    }
    cout << ans << endl;
    return 0;
}