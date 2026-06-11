#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
using vp = vector<pair<int,int>>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main(){
    int h,w,k;cin >> h >> w >> k;
    vector<vector<char>> in(h,vector<char>(w));
    rep(i,h) rep(j,w) cin >> in[i][j];
    int ans = 0;
    rep(tmp,(1 << h+w)){
        bitset<12> s(tmp);
        int sum = 0;
        rep(i,h){
            if(s.test(i)) continue;
            rep(j,w){
                if(s.test(h+j)) continue;
                if(in[i][j] == '#') sum++;
            }
        }
        if(sum == k) ans++;
    }
    cout << ans << endl;
}