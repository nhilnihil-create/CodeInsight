#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;



void _sol(){
    int h,w,m; cin >> h >> w >> m;
    vector<int> row(h+1,0) , col(w+1,0);
    unordered_map<int,map<int,int>> mp;
    forr(i,m){
        int u,v; cin >> u >> v;
        row[u]++;
        col[v]++;
        mp[u][v]++;
    }
    vector<pair<int,int>> v1,v2;
    for(int i=1;i<=h;i++){
        v1.push_back({row[i] , i});
    }
    for(int i=1;i<=w;i++){
        v2.push_back({col[i] , i});
    }
    sort(v1.rbegin(),v1.rend()); sort(v2.rbegin(),v2.rend());
    int ans = INT_MIN;
    for(int i=1;i<=w;i++){
        ans = max(ans , v1[0].first + v2[i-1].first - mp[v1[0].second][v2[i-1].second]);
    }
    for(int i=1;i<=h;i++){
        ans = max(ans , v1[i-1].first + v2[0].first - mp[v1[i-1].second][v2[0].second]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
