#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 2e5+5;


vector<ll>ans,veca,vecb;
vector<int>adj[N];
vector<double>aka;
vector<pair<int,double>>dp[N];
vector<bool>vis;


void init(int n){
    ans.clear();veca.clear();aka.clear();vis.clear();ans.resize(n);
    vecb.clear(),vecb.resize(n);veca.resize(n);vis.resize(n);
    for (int i = 0; i <n; i++) {
        vis[i]=0;
    }
    for (int i = 0; i<=n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i <=n; i++) {
        dp[i].clear();
    }
    for (int i = 0; i < n; i++) {
        ans[i]=0;
    }
}


void solve(){
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
 
    ll straight = min(K, X / D);
    K -= straight;
    X -= straight * D;
 
    if (K % 2 == 0) {
        cout << X << endl;
    } else {
        cout << D - X << endl;
    }

    
    
}

int main(){
   
   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
        
        
    return 0;
}