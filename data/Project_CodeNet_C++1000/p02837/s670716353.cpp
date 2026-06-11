#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n;cin >> n;
    vector<vector<P>> G(n);
    rep(i,n){
        int a;cin >> a;
        rep(j,a){
            int x,y;cin >> x >> y;
            --x;
            G[i].push_back(make_pair(x,y));
        }
    }
    int ans = 0;
    rep(i,1<<n){
        vector<int> horu(n,-1);
        bool flag = true;
        int temp = 0;
        rep(j,n){
            if(i>>j&1) {
                horu[j] = 1;
            }else horu[j] = 0;
        }
        rep(j,n) if(horu[j]) for(P p:G[j]) if(horu[p.first]!=p.second) flag = false;
        if(flag) ans = max(ans,__builtin_popcount(i));
    }

    cout << ans << endl;
}