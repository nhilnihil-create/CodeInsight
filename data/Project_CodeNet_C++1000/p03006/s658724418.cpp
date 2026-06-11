#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n;
    cin >> n;
    vector<P> pos(n);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        pos[i] = make_pair(x,y);
    }
    map<P,int> mp;
    rep(i,n){
        for(int j = 0;j<n;j++){
            if(i==j) continue;
            P p = make_pair(pos[i].first-pos[j].first,pos[i].second-pos[j].second);
            mp[p]+=1;
        }
    }

    int ans = n;
    int cnt = 0;
    for(auto p:mp){
        cnt = max(cnt,p.second);
    }
    ans -= cnt;
    cout << ans << endl;

 }