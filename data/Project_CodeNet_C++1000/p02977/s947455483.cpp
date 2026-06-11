#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define rn return
#define fi first
#define se second
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;



int main(){
    int N; cin >> N;
    if (__builtin_popcount(N) == 1){ cout << "No"; rn 0;};
    cout << "Yes" << endl;
    
    vector<vector<int>> ans(2*N+1,vector<int>());
    
    if (N%2 == 1){
        FOR(i,2,N+1){
            if (i%2==0){
                ans[1].emplace_back(i);
                ans[i].emplace_back(i+1);
            }
            else{
                ans[1].emplace_back(i+N);
                ans[i+N].emplace_back(i+N-1);
            }
        }
    }
    else{
        FOR(i,2,N){
            if (i%2==0){
                ans[1].emplace_back(i);
                ans[i].emplace_back(i+1);
            }
            else{
                ans[1].emplace_back(i+N);
                ans[i+N].emplace_back(i+N-1);
            }
        }
        int largestBit = 0;
        while(1<<largestBit < N){
            largestBit++;
        }
        largestBit--;
        ans[1<<largestBit].emplace_back(N);
        ans[N+1-(1<<largestBit)+N].emplace_back(2*N);
    }
    ans[2+N].emplace_back(1+N);
    
    FOR(i,1,N+1){
        for (auto& a:ans[i]){
            cout << i << " " << a << endl;
        }
        for (auto& a:ans[i+N]){
            cout << N + i << " " << a << endl;
        }
        
    }
    

}


int mainB(){
    int N,M; cin >> N >> M;
    if (M%2 == 1){cout << "-1"; rn 0;}
    vector<vector<int>> g(N);
    rep(i,M){
        int x,y;
        cin >> x >> y; x--;y--;
        g[y].emplace_back(x);
        g[x].emplace_back(y);
    }
    
    vector<pair<int,int>> ans;
    vector<int> degree(N,0);
    vector<int> depth(N,-1);
    
    function<void(int,int)> DFS=[&](int v, int pr){
        for(int u:g[v]){
            if (depth[u] == -1){
                depth[u] = depth[v] + 1;
                DFS(u,v);
            }
            else if(depth[u]>depth[v]) {
                degree[v]++;
                ans.emplace_back(v,u);
            }
        }
        if (degree[v]%2 == 1){
            ans.emplace_back(v,pr);
            degree[v]++;
        }
        else{
            if(pr!=-1){
                ans.emplace_back(pr,v);
                degree[pr]++;
            }
        }
    };
    

    
    depth[0] = 0;
    DFS(0,-1);
    
    for (auto& p:ans){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    rn 0;
}


int mainA(){
    int N;cin >> N;
    vector<int> a(N);
    map<int,int> cnt;
    rep(i,N) {cin >> a[i];cnt[a[i]]++;}
    if (cnt[0] == N) { cout << "Yes"; rn 0;}
    if (N%3!=0) { cout << "No"; rn 0;}
    
    vector<int> all;
    for(auto& e:cnt){
        rep(i,e.second/(N/3)) all.emplace_back(e.first);
    }
    if (all.size() == 3 && (all[0]^all[1]^all[2]) == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    rn 0;
}
