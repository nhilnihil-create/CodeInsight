#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int n;
vector<vector<pair<int,int>>> tes(15,vector<pair<int,int>>());

bool isConsistent(bitset<15> s){
    bool res = true;
    rep(i,n){
        if(!s.test(i)) continue;
        for(auto p : tes[i]){
            if(s.test(p.first) != p.second) res = false;
        }
    }
    return res;
}

int main() {
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            tes[i].push_back(make_pair(x,y));
        }
    }
    int ans = 0;
    for(int bit = 0;bit < (1<<n);bit++){
        bitset<15> s(bit);
        if(isConsistent(s)) ans = max(ans,(int)s.count());
    }
    cout << ans << endl;
}