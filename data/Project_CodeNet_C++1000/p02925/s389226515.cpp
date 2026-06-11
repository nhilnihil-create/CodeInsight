#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> mp(n*n,0);
    vector<vector<int>> G(n*n);
    rep(i,n){
        int a,b,aa,bb;
        cin >> a; a--; b = i; // 0-indexed
        if(a > b) swap(a,b); // a < b
        rep(j,n-2){
            cin >> aa; aa--; bb = i; // 0-indexed
            if(aa > bb) swap(aa,bb); // aa < bb
            G[a*n+b].pb(aa*n+bb);
            mp[aa*n+bb]++;
            a = aa; b = bb;
        }
    }

    int ans = 0;
    queue<int> que1;
    rep(i,n*n) if(mp[i] == 0) que1.push(i);
    while(true){
        ans++;
        queue<int> que2;
        while(!que1.empty()){
            int v = que1.front(); que1.pop();
            for(auto nv : G[v]){
                mp[nv]--;
                if(mp[nv] == 0) que2.push(nv);
            }
        }
        que1 = que2;
        if(que1.empty()) break;
    }

    bool check = true;
    rep(i,n*n) if(mp[i] != 0) check = false;
    if(check) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}